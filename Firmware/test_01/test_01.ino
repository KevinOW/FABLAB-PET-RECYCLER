#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "steppers.h"

LiquidCrystal_I2C lcd(0x3F, 16, 2);

// TERMO - Thermistor code is kept in this main file as it's small.

const int sensor = 0;
const int powerPin = 2;
int rawValue = 0;
const int r1 = 99800;
const int r0 = 100000;
const int b = 4700.0;
const int t0 = 298.15;
int counter = 0;
double average = 0;

void setup()
{
  Serial.begin(9600);
  initLCD();
}

void loop()
{
  taskLCD();
}

// Add the thermistor code if needed
