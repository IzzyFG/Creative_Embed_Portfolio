#include <Arduino.h>
// #include <TFT_eSPI.h>    // Hardware-specific library

/* button variables */
int btnPressed = -1;
int btnPin = 8; 
int res[] = {0};
/*joy-stick variables*/
int joyPins[] = {36, 2, 14};   //x,y,z pins

/*score variables*/
int score[] = {0};
int oldScore[] = {score[0]};
int leds[] = {8,0}; //red, blue

/*TODO: add timer?*/
/*flashes score on led*/
/* change to show score on screen?*/
void showScore(){
	delay(2000);
	for (int i =0; i<score[0]; i++){
		digitalWrite(leds[0], HIGH);
		delay(500);
		digitalWrite(leds[0], LOW);
		delay(500);
	}
}

void setup() {
	// put your setup code here, to run once:
	
	Serial.begin(115200);
	pinMode(joyPins[2], INPUT_PULLUP);  //z axis is a button.
	pinMode(btnPin, INPUT);

	/* TODO: need to make a virtual resistance for button*/
	while(res[0] == 0){
		res[0] =  analogRead(btnPin);
	}
	while (analogRead(btnPin)!=0){

	}

}

/* when button is pressed select item */
void pressedBtn(int b){
	/**/
	while(digitalRead(btnPin) !=1){
		Serial.println(digitalRead(btnPin));
		delay(500);
		/*print to screen selection*/
	}
	btnPressed = -1;
	if(!compArr(score, oldScore, 2)){
		showScore();
	}
}

bool compArr(int *arr1, int *arr2, int l){
	for (int j = 0; j<1; j++){
		if (arr1[j]!=arr2[j]){
			return false;
		}
	}
	return true;
}

void selectBox(int xVal, int yVal){
	/*left*/ 
	if(yVal <=511 && yVal > 0){
		/*top*/
		if(xVal <=511 && xVal > 0){
			//box1
		}
		/*bottom*/
		if(yVal <=511 && yVal > 0){
			//box2
		}
	}
	/*right */
	if(yVal <=1023 && yVal > 511){
		/*top*/
		if(xVal <=511 && xVal > 0){
			//box3
		}
		/*bottom*/
		if(yVal <=511 && yVal > 0){
			//box4 
			
		}
	}
}

void checkAnswer(){

}


/* put your main code here, to run repeatedly */
void loop() {
	oldScore[0] = score[0];
	int xVal = analogRead(joyPins[0]);
	int yVal = analogRead(joyPins[1]);
	// int zVal = digitalRead(joyPins[2]);
	int m = analogRead(btnPin);

	/*highlight current selction*/
	selectBox(xVal, yVal);

	if(res[0]-1 < m ) {
		btnPressed == 0;
		checkAnswer();
	}



	// Serial.printf("%d\t%d\t%d\n", xVal, yVal, zVal);
	// int buttonVal = digitalRead(25);
	// Serial.print(buttonVal);
	// Serial.print('\n');
	// delay(100);
}