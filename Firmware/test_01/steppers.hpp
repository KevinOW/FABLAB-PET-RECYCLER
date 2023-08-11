/*

Steppers code

This code is used for the step motors.
In additon to that we connected a potentiometer to controll the step motors.

*/


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
