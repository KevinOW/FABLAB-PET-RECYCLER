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
    lcd.clear();
    delay(1);
    lcd.setCursor(0, 0);
    lcd.print("Speed : ");
    lcd.setCursor(2, 1);
  }
}