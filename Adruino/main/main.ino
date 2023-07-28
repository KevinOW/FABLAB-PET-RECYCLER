/* 

  This the main program that will run the PET recycling machine that is made in FabLab 
  at Halmstad University. 

  Authors: Kevin Volmhagen & Gustav Ferdman

  Version: 0.1

  PINs used: 

  Fan PINs:
                     
  Load Cell Amplifier PINs:
                     
  LCD 16x2 with I2C PINs:
                     
  Potentiometer PINs:
                     
  Potentiometer PINs:


*/                     

  /* LCD Libary Imports & Setup */
  #include <Wire.h>                   // Libary import
  #include <LiquidCrystal_I2C.h>      // Libary import
  LiquidCrystal_I2C lcd(0x3F, 16, 2); // LCD Setup
  unsigned long LCDCounter = 0;        // Counter for LCD


  /* Step Motors Configuration */ 
  unsigned long counter = 0;          // Counter for step motors
  const int dir = 2;                  // Can be high or low, decides the direction of the motor
  const int step = 3;                 // When turned high the motor performs one step, aka turns 1,8 degrees. Must remain high for at least a couple of microseconds.
  int speed = 10;                     // Inverted, lower is faster.
  bool check = 0;

  /* PID Configuration */


  /* Potentiometer Configuration */
  const int pot = 0;                  // Potentiometer
  int potRead = 0;                    // Read the output of the potentiometer



void setup() {
  // Initialize LCD & Turn on the background light
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // Step Motor Setup Configuration
  pinMode(dir, OUTPUT);
  pinMode(step, OUTPUT);
  Serial.begin(9600);               // Sets the baudrate for serial communication, can be put to something higher but must match the setting in serial monitor while running.
  digitalWrite(dir, HIGH);

  // Potentiometer Setup
  pinMode(pot, INPUT); 


}

void loop() {
  // LCD
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

  // Step Motors 
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
