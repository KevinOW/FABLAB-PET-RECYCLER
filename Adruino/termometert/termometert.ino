const int thermo = 0;
long read = 0;
long sum = 0;
const int offset = -30;
const int numPoints = 10;


void setup() {
Serial.begin(9600);
pinMode(thermo, INPUT);
}

void loop() {
  int sum = 0;
  for(int i = 0; i <= numPoints; i++){
    read = 1023 - analogRead(thermo);
    read = read + offset;
    sum = sum + read;
  }
  sum = sum / (numPoints+1);
  Serial.print("average = ");
  Serial.println(sum);

delay(1000);

}
