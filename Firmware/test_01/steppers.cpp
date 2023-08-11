#include <Arduino.h>  // Include this if you're using Arduino IDE or other platforms that require it.
#include "steppers.h"

const int dir = 2;
const int step = 3;
const int pot = 0;
int speed = 10;
int potRead = 0;
bool check = 0;

void initStep()
{
  pinMode(dir, OUTPUT);
  pinMode(step, OUTPUT);
  Serial.begin(9600);
  digitalWrite(dir, HIGH);
  pinMode(pot, INPUT);
}

void taskStep()
{
  digitalWrite(dir, HIGH);

  if (millis() - counter >= speed && check == 0) {
    counter = millis();
    digitalWrite(step, LOW);
    check = 1;
  }

  if (millis() - counter >= speed && check == 1) {
    counter = millis();
    digitalWrite(step, HIGH);
    check = 0;
  }
}
