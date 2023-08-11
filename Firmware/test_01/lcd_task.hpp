#ifndef LCD_TASK_H
#define LCD_TASK_H

#include <Arduino.h> // Include this for Arduino specific types (e.g., byte, int)

extern int potRead;
extern int speed;
extern const int pot;

void initLCD();
void taskLCD();

#endif // LCD_TASK_H