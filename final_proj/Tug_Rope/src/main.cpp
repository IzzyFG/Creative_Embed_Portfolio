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
int motorPorts[] = {14, 27, 26, 25};
int btnPins[] = {0, 4, 2}; //p1,p2, reset
// int resetPin = 2;
/* pin information end */

/* player variables */
int btnLast[] = {-1, -1}; /*last pressed values of p1, p2*/
int btnTime[] = {-1, -1}; /*last pressed values of p1, p2*/
unsigned long startTime, endTime1, endTime2;
short timerRunning;
/* player variables end */

/* motor variables */
int steps;        // Used to set HOME position + == CW - == CCW
/* motor variables */

//declare reset function at address 0
void(* resetFunc) (void) = 0;

/* player/button functions*/

/*
 * checks whether button IS pressed and was released from previous
 * compares the time for each button to see which was pressed first
 */
void whichPlayer()
{
	/* read both immediately to limit time spent running code after */
	int pr1 = digitalRead(btnPins[0]);
	int pr2 = digitalRead(btnPins[1]);

	/* check if either buttons have been pressed*/
	if (timerRunning == 1 && pr1 && !btnLast[0])
	{
		endTime1 = millis();
		btnTime[0] = endTime1 - startTime;
	}
	if (timerRunning == 1 && pr2 && !btnLast[1])
	{
		endTime2 = millis();
		btnTime[1] = endTime2 - startTime;
	}

	btnLast[0] = pr1;
	btnLast[1] = pr2;
	
}

/*
 * TODO: 
 * - check for reset button 
 * - possibly add a win by x amount for button press (15ms/.015s ?)
 */
int pull()
{
	// timer not running already
	if (timerRunning == 0)
	{ 
		startTime = millis();
		timerRunning = 1;
		btnTime[0] = -1;
		btnTime[1] = -1;
	}

	int winner = 0; 
	
	while(timerRunning == 1)
	{

		whichPlayer();

		if (btnTime[0]>btnTime[1])
		{
			timerRunning = 0;
			winner = 1;
		}
		else if (btnTime[1]>btnTime[0])
		{
			timerRunning = 0;
			winner = -1;
		}
	}

	return winner;
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
	tft.setTextDatum(TC_DATUM);
	tft.fillScreen(TFT_BLUE);
	tft.setTextColor(TFT_WHITE, TFT_BLUE);

	for (int i = 0; i<size; i++){
		tft.drawString(msg[i], x, y);
		y+=35;
	}
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
	for (int i = 0; i < 3; i++)
	{
		pinMode(btnPins[i], INPUT_PULLUP);
	}
	
	tft.begin();
	textSetup();
	delay(5);
}

/*TODO: need to determine rotation amounts for string

 * "The rotor (or output shaft) of the stepper motor is connected to a speed
 * reduction set of gears and the reduction ratio is 1:64."- txtbk p. 214
 * 4^3 = 64
 */

void loop()
{
	/* reset button pressed */
	if (digitalRead(btnPins[2]) == LOW){ 
		resetMotor();
		steps = 0;
		btnLast[0] = -1;
		btnLast[1] = -1;

		resetFunc();
	}
	srand((unsigned) time(NULL));
	

	const char * msg[3] ={"Tug of War:","The ultimate test of","speed and strength"};
	int size = sizeof(msg)/sizeof(msg[0]);

	showmsg(msg, size);
	delay(6000);

	const char * msg2 [3]= {
		"But strength and","speed isn't all.","Timing is key."};
	size = sizeof(msg2)/sizeof(msg2[0]);
	showmsg(msg2, size);
	delay(6000);
	const char * msg3 [1]= {"Get ready!"};
	showmsg(msg3, 1);
	delay(6000);


	bool won = false; // when string reaches x point won = true

	while (won == false){
		int player = pull();
		bool direction = player>0?true:false;

		moveSteps(direction, 32*4, 4);
		steps += player * 32*4;

	}
}