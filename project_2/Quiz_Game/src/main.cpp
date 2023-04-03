#include <Arduino.h>

/* button variables */
// int btnPressed = -1;
int btnPin = 26; //btn pin
/*joy-stick variables*/
int joyPins[] = {25, 32, 33};   //x,y,z pins

void setup() {
	Serial.begin(115200);
	pinMode(joyPins[2], INPUT_PULLUP);  //z axis is a button.
	pinMode(btnPin, INPUT);

}


/* put your main code here, to run repeatedly */
void loop() {
	int xVal = analogRead(joyPins[0]);
	int yVal = analogRead(joyPins[1]);
	// int zVal = digitalRead(joyPins[2]);
	int btn = digitalRead(btnPin) ;

	Serial.printf("%d\t%d\t%d\n", xVal, yVal, btn);
	delay (500);
}