#include <Arduino.h>

int xyzPins[] = {36, 2, 14};   //x,y,z pins
void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(115200);
  pinMode(xyzPins[2], INPUT_PULLUP);  //z axis is a button.
}

void loop() {
  // put your main code here, to run repeatedly:
  int xVal = analogRead(xyzPins[0]);
  int yVal = analogRead(xyzPins[1]);
  int zVal = digitalRead(xyzPins[2]);
  Serial.printf("%d\t%d\t%d\n", xVal, yVal, zVal);
  // int buttonVal = digitalRead(25);
  // Serial.print(buttonVal);
  // Serial.print('\n');
  // delay(100);
}