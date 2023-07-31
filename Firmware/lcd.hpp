#include "steppers.hpp"             // Import Steppers.hpp
#include <Wire.h>                   // Libary import
#include <LiquidCrystal_I2C.h>      // Libary import
LiquidCrystal_I2C lcd(0x3F, 16, 2); // LCD Setup

unsigned long LCDCounter = 0;

void initLCD()
{
    lcd.init();
    lcd.backlight();
    lcd.clear();
}

void taskLCD()
{
  if (millis() - LCDCounter >= 100) {
    LCDCounter = millis();
    potRead = analogRead(pot);
    speed = map(potRead, 16, 1008, 4, 50);
    lcd.clear();
    delay(1);
    lcd.setCursor(0, 0);
    lcd.print("Speed : ");
    lcd.print(          potRead);
    lcd.setCursor(2, 1);
    lcd.print(speed);
  }
}