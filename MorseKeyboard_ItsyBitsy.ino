#include<Keyboard.h>
#include "morseKeyboard.h"

int buzzerPin = 7;
int debounceTime = 100;
int ditPin = 11;
int dahPin = 10;
int ditSound = 880;
int dahSound = 500;
int ditSoundDuration = 400;
int dahSoundDuration = 450;
int speedTyper = 300;
int speedSense = 3;
int accessPin = 13;

char ditKey = 46;
char dahKey = 45;
char altDitKey = 204;
char altDahKey = 205;

KeyboardKey shortKey(ditPin, ditKey, altDitKey, debounceTime, buzzerPin, ditSound, ditSoundDuration);
KeyboardKey longKey(dahPin, dahKey, altDahKey, debounceTime, buzzerPin, dahSound, dahSoundDuration);
//AccessKey accessButton(accessPin, debounceTime);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  //speedTyper = analogRead(A4)/speedSense;
  speedTyper = 500;
  
  //bool shiftValue = bleAccessButton.Check();
  
  bool shiftValue = false;
  shortKey.Press(shiftValue, speedTyper);
  longKey.Press(shiftValue, speedTyper);
}
