#include <Arduino.h>
#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h

/* pin information */
int motorPorts[] = {14, 27, 26, 25};
int btnPins[] = {0, 4, 2}; //p1,p2, reset
// int resetPins = 2;
/* pin information end */

/* global variables */
int btnLast[] = {-1, -1}; /*last pressed values of p1, p2*/
int btnPress[] = {false, false}; /*last pressed values of p1, p2*/
unsigned long startTime, endTime1, endTime2;
short timerRunning;
/* global variables end */


/*
 * checks whether button IS pressed and was released from previous
 * compares the time for each button to see which was pressed first
 */
void whichPlayer() {
	/* read both immediately to limit time spent running code after */
	int pr1 = digitalRead(btnPins[0]);
	int pr2 = digitalRead(btnPins[1]);

	/* check if either buttons have been pressed*/
	if (timerRunning == 1 && pr1 && !btnLast[0]){
		endTime1 = millis();
		btnPress[0] = endTime1 - startTime;
	}
	else if (timerRunning == 1 && pr2 && !btnLast[1])
	{
		endTime2 = millis();
		btnPress[1] = endTime2 - startTime;
	}

	btnLast[0] = pr1;
	btnLast[1] = pr2;
	
}

/*
 * TODO: check for reset button 
 */
int pull(){
	// button pressed & timer not running already
	if (timerRunning == 0){ 
		startTime = millis();
		timerRunning = 1;
	}
}


void setup() {
	// set motor pins to output
	for (int i = 0; i < 4; i++) {
		pinMode(motorPorts[i], OUTPUT);
	}

	// set btn pins to input w/ internal resistors
	for (int i = 0; i < 3; i++) {
		pinMode(btnPins[i], INPUT_PULLUP);
	}
	
}

void loop() {
	// put your main code here, to run repeatedly:
}