/*

Steppers code

This code is used for the step motors.
In additon to that we connected a potentiometer to controll the step motors.

*/

unsigned long counter = 0;          // Counter for step motors
const int dir = 2;                  // Can be high or low, decides the direction of the motor
const int step = 3;                 // When turned high the motor performs one step, aka turns 1,8 degrees. Must remain high for at least a couple of microseconds.
const int pot = 0;                  // Potentiometer
int speed = 10;                     // Inverted, lower is faster.
int potRead = 0;                    // Read the output of the potentiometer
bool check = 0;

void initStep()
{
  pinMode(dir, OUTPUT);
  pinMode(step, OUTPUT);
  Serial.begin(9600);               // Sets the baudrate for serial communication, can be put to something higher but must match the setting in serial monitor while running.
  digitalWrite(dir, HIGH);
  pinMode(pot, INPUT);
}

void taskStep()                        // Void loop works like while(true) and is mandatory. Feel free to make other methods or classes when needed.
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
