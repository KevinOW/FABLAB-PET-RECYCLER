/*

  This the main program that will run the PET recycling machine that is made in FabLab
  at Halmstad University.

  Authors: Kevin Volmhagen & Gustav Ferdman

  Version: 0.1

*/

#include "steppers.hpp"
#include "calibration.hpp"
#include "loadcell.hpp"
#include "termo.hpp"
#include "lcd.hpp"
#include "smelter.hpp"

void setup() {
    delay(20);
    Serial.print("MACHINE IS STARTING")
    initCalibration();
    initLoadCell();
    initTermo();
    initLCD();
    initStep();
}

void loop() {
    taskCalibration();
    taskLoadCell();
    taskTermo();
    taskLCD();
    taskStep();
}