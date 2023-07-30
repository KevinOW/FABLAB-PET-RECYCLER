const int thermo = 0;
long read = 0;
long sum = 0;
const int offset = -30;
const int numPoints = 10;
const float Vi = 5.0; // Input voltage in volts
const float R1 = 100000.0; // Series resistor value in ohms
const float R0 = 100000.0; // Thermistor resistance at 25 degrees Celsius in ohms
const float B = 4700.0; // Thermistor coefficient

void setup() {
  Serial.begin(9600);
  pinMode(thermo, INPUT);
}

void loop() {
  int sum = 0;
  for (int i = 0; i <= numPoints; i++) {
    read = 1023 - analogRead(thermo);
    read = read + offset;
    sum = sum + read;
  }
  sum = sum / (numPoints + 1);

  // Calculate voltage after voltage division (Vo)
  float denominator = Vi - (sum * Vi / 1023.0);
  float Vo = (denominator != 0) ? (Vi * R1) / denominator : 0;

  // Calculate temperature in Celsius
  float T = B / log(((Vo * R1) / (Vi - Vo)) / (R0 * exp(-B / (25.0 + 273.15))));
  float Tc = T - 273.15;

  if (!isnan(Tc)) {
    Serial.print("Average temperature = ");
    Serial.print(Tc);
    Serial.println(" degrees Celsius");
  } else {
    Serial.println("Error: Unable to calculate temperature");
  }

  delay(1000);
}
