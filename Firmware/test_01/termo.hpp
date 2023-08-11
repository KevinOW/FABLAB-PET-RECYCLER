#include <math.h>

const int sensor = 0;
const int powerPin = 2;
int rawValue = 0;      // 0 to 1023
const int r1 = 99800;  // 100K resistor
const int r0 = 100000; // Thermistorns resistans vid 25 C
const int b = 4700.0;  // Koeffcient för thermistorn.
const int t0 = 298.15; // Rumstemperatur, 25 C, 298,15 kelvin.
int counter = 0;
double average = 0;

void initTermo()
{
    Serial.begin(9600);
    pinMode(sensor, INPUT);
    pinMode(powerPin, OUTPUT);
}

void taskTermo()
{
    digitalWrite(powerPin, HIGH); // Using I/O to control the power of the sensor so that it doesn't heat up by factors other than its surroundings
    delay(50);
    rawValue = analogRead(sensor);
    digitalWrite(powerPin, LOW);
    double r2 = double(r1) / (1023.0 / rawValue - 1.0);
    double tc = double(b) / (log(r2 / (double(r0) * exp(-b / double(t0))))) - 273.15; // Sluttemperatur i celcius
    average = average + tc;

    counter++;
    if (counter == 4)
    {
        average = average / counter;
        Serial.print("rawValue: ");
        Serial.print(rawValue);
        Serial.print("  - Celcius: ");
        Serial.println(average);
        counter = 0;
        average = 0;
    }

    delay(50);
}