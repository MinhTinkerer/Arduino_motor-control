/*
Framework to handle button presses in a logical way, christ sakes that seemed whay more difficult that it looked.
But at least I have a class I can use elsewhere!
 */

#include <SerialLCD.h>
#include <SoftwareSerial.h> //this is a must
#include <Tap.h>

SerialLCD slcd(11,12); //Initialize the lcd lib.

const int rightRed = 5; //right red button
const int leftRed = 4; //left red button
const int greenMenu = 3; //green menu button
const int yellowEnter = 8; //yellow enter button, I/O 2
const int leftLimit = 7; //left limit switch. Green/White twisted pair.
const int rightLimit = 6; //right limit switch. Blue/White twisted pair.

int var = 0;

Tap green(greenMenu);
Tap right_Rb(rightRed);
Tap left_Rb(leftRed);
Tap yellow(yellowEnter);

void setup() { //int yer inpins

  pinMode(rightRed, INPUT); 
  pinMode(leftRed, INPUT);
  pinMode(greenMenu, INPUT);
  pinMode(yellowEnter, INPUT);
  pinMode(leftLimit, INPUT);
  pinMode(rightLimit, INPUT);
  
  Serial.begin(9600);
  slcd.begin();
  slcd.backlight();

}

void loop() {
if (green.isHit()) {
  var++;
  slcd.setCursor(0,0);
  slcd.print("green");
  slcd.setCursor(0,1);
  slcd.print(var, DEC);
}
if (right_Rb.isHit()) {
  var++;
  slcd.setCursor(0,0);
  slcd.print("right red");
  slcd.setCursor(0,1);
  slcd.print(var, DEC);
}
if (left_Rb.isHit()) {
  var++;
  slcd.setCursor(0,0);
  slcd.print("left red");
  slcd.setCursor(0,1);
  slcd.print(var, DEC);
}
if (yellow.isHit()) {
  var++;
  slcd.setCursor(0,0);
  slcd.print("yellow");
  slcd.setCursor(0,1);
  slcd.print(var, DEC);
}
}

/* This part seems to lose a button press if done quickly
Im not sure if it due to the code or due to the hysteresis 
in the schmitt trigger
*/

boolean buttonHandler(int buttonRead){

static boolean oldButtonState = false;

boolean buttonState = digitalRead(buttonRead);
boolean oldButton = oldButtonState;

if (buttonState && !oldButtonState) {
  var++;
  oldButtonState = buttonState;
}
else {
  oldButtonState = false;
}
}


