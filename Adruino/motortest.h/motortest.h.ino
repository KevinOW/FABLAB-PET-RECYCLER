#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2); 
unsigned long counter = 0; 
unsigned long counter_2 = 0;
const int dir = 2;   //Can be high or low, decides the direction of the motor
const int step = 3;  //When turned high the motor performs one step, aka turns 1,8 degrees. Must remain high for at least a couple of microseconds.
const int pot = 0;
int speed = 10; //Inverted, lower is faster.
int potRead = 0;
bool clockWise = 1;
bool counterClockWise = 0;
bool check = 0;

void setup() {
lcd.init();
lcd.backlight();
lcd.clear();
pinMode(dir, OUTPUT);   
pinMode(step, OUTPUT);
Serial.begin(9600); //Sets the baudrate for serial communication, can be put to something higher but must match the setting in serial monitor while running.
digitalWrite(dir, HIGH);
pinMode(pot, INPUT);
}

void loop() {   //Void loop works like while(true) and is mandatory. Feel free to make other methods or classes when needed.
if(millis() - counter_2 >= 100){
  counter_2 = millis();
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

digitalWrite(dir, HIGH);

if (millis() - counter >= speed && check == 0){
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
