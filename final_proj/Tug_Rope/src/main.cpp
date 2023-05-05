// #include <Arduino.h>
#include <TFT_eSPI.h> // Graphics and font library
#include <SPI.h>

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>  


TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h

/* pin information */
int motorPorts[] = {27, 26, 25, 33};
int btnPins[] = {12, 13, 15}; //p1,p2, reset
/* pin information end */

/* player variables */
volatile bool btnpressed, btn1press,  btn2press, resetbtn;
// int player;
// unsigned long btn_time, last_btn_time = 0;
// short timerRunning;
/* player variables end */

/* motor variables */
int steps; // Used to set HOME position + == CW - == CCW
/* motor variables end*/

//declare reset function at address 0
void(* resetFunc) (void) = 0;

/* player/button functions*/

/*
 * checks whether button IS pressed and was released from previous
 * compares the time for each button to see which was pressed first
 */
void IRAM_ATTR playerOne()
{
	// btn_time = millis();
	// if(!plrbtn && btn_time-last_btn_time>250){
	btnpressed = true;
		// last_btn_time = btn_time;
	btn1press = true;
	// }
}

void IRAM_ATTR playerTwo()
{
	// btn_time = millis();
	// if(!plrbtn && btn_time-last_btn_time>250){
	btnpressed = true;
	// 	last_btn_time = btn_time;
	// btnpressed = 2;
	btn2press = true;

	// }
}

void IRAM_ATTR resetBtn()
{
	btnpressed = true;
	resetbtn = true;
}

/* motor functions */

/*
 * true = cw
 * false = ccw
 */
void moveOneStep(bool dir) {
	// Define a variable, use four low bit to indicate the state of port
	static byte out = 0x01;
	// Decide the shift direction according to the rotation direction
	if (dir) { // ring shift clock-wise
		out != 0x08 ? out = out << 1 : out = 0x01;
	}
	else { // ring shift counterclock-wise
		out != 0x01 ? out = out >> 1 : out = 0x08;
	}
	// Output singal to each port
	for (int i = 0; i < 4; i++) {
		digitalWrite(motorPorts[i], (out & (0x01 << i)) ? HIGH : LOW);
	}
}

void moveSteps(bool dir, int steps, byte ms) {
	for (unsigned long i = 0; i < steps; i++) {
		moveOneStep(dir); // Rotate a step
		delay(constrain(ms,3,20)); // Control the speed
	}
}

/* reset motor to starting location */
void resetMotor(){
	bool direction = steps>0?true:false;
	moveSteps(direction, abs(steps), 20);
}

/* display functions */
void textSetup(){
	tft.init();
	tft.setRotation(1);
	tft.resetViewport();
	tft.invertDisplay(true);
	tft.fillScreen(TFT_BLACK);
	tft.setTextColor(TFT_CYAN, TFT_BLACK);
	tft.setTextFont(4);
	tft.setCursor(4, 4);
	tft.setTextWrap(true); // Wrap on width
}

/*
 * NOTE: if you try to find size of the string here it will fail for some reason
 * TODO: add smthn to justify vertically
 */
void showmsg(const char * msg[], int size)
{
	int32_t x = 120;
	int32_t y = 15;
	tft.setTextSize(1);
	tft.setTextDatum(TC_DATUM);
	tft.fillScreen(TFT_NAVY);
	tft.setTextColor(TFT_SILVER, TFT_NAVY);

	for (int i = 0; i<size; i++){
		tft.drawString(msg[i], x, y);
		y+=35;
	}
}

void showLone(const char * msg, int col){
	int32_t x = 120;
	int32_t y = 70;
	tft.setTextSize(2);
	tft.setTextDatum(CC_DATUM);
	tft.fillScreen(col);
	tft.setTextColor(TFT_WHITE, col);

	tft.drawString(msg, x, y);
}

void startMessage(){
	const char * msg[3] ={"Tug of War:","The ultimate test of","speed and strength"};
	showmsg(msg, 3);
	delay(4000);

	const char * msg2 [3]= {
		"But strength and","speed isn't all.","Timing is key."};
	showmsg(msg2, 3);
	delay(4000);

	const char * msg3 [2]= {
		"Press your button","to pull the rope"};
	showmsg(msg3, 2);
	delay(3000);

	showLone("Get ready!", TFT_MAROON);
	delay(3000);
}

/* setup and loop*/
void setup()
{
	
	Serial.begin(115200);
	// set motor pins to output
	for (int i = 0; i < 4; i++)
	{
		pinMode(motorPorts[i], OUTPUT);
	}

	// set btn pins to input w/ internal resistors
	//plyr1
	pinMode(btnPins[0], INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(btnPins[0]), playerOne, RISING);

	//plyr2
	pinMode(btnPins[1], INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(btnPins[1]), playerTwo, RISING);

	//resetbutton
	pinMode(btnPins[2], INPUT_PULLUP);

	
	tft.begin();
	textSetup();
	delay(5);
}

/*TODO: need to determine rotation amounts for string

 * "The rotor (or output shaft) of the stepper motor is connected to a speed
 * reduction set of gears and the reduction ratio is 1:64."- txtbk p. 214
 * 4^3 = 64
 */


bool pull(int plyr, bool won){
	noInterrupts();
	showLone("in pull", TFT_ORANGE);

	bool direction = plyr>0?true:false;

	moveSteps(direction, 32*4, 4);
	steps += plyr * 32*4;
	
	char * msg;
	int pulled = plyr>0? 1: 2;
	sprintf(msg, "Player %d Pulled", pulled);
	showLone(msg, TFT_ORANGE);
	delay(3000);

	if (abs(steps) == 32*64){
		won = true;
	}
	if (won == false){
		showLone("...wait", TFT_MAROON);
		delay(rand()%10*1000);
		showLone("PULL!!", TFT_DARKCYAN);
	}
	interrupts();
	return won;
}

void loop()
{
	noInterrupts();
	/* reset button pressed */
	if (digitalRead(btnPins[2]) == LOW){ 
		resetMotor();
		steps = 0;
	// 	btnpressed = false;
	// 	plrbtn = 0;

		resetFunc();
	}

	startMessage();

	srand((unsigned) time(NULL));
	
	delay(2000);
	interrupts();
	showLone("PULL!!", TFT_DARKCYAN);

	bool won = false; // when string reaches x point won = true

	int player = 0;
	bool direction;
	while (won == false){

		if(btnpressed == true){
			noInterrupts();
			if(btn1press){
				player = 1;
			}
			if(btn2press){
				player = -1;
			}
			interrupts();
			won = pull(player, won);
		}
		if(!won){
			player = 0;
		}
		else{
			player = player>0? 1: 2;
		}
	}

	char * winner;
	sprintf(winner, "Player %d Wins", player);

	showLone(winner, TFT_ORANGE);
}