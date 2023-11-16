#define TMP36_INPUT 0  // A0
#define CDS_INPUT 1    // A1
#define HUMIDITY_PIN A2 // Use an available analog pin for simulating humidity

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0)); // Initialize the random number generator
}

void loop() {
  // Temperature from TMP36
  int temp_value = analogRead(TMP36_INPUT);
  float voltage = temp_value * 5.0 * 1000;  // in mV
  voltage /= 1023.0;
  float tempC = (voltage - 500) / 10 ;  // in C

  // Lux from CdS (LDR)
  int cds_value = analogRead(CDS_INPUT);
  int lux = int(luminosity(cds_value));  // in lux

  // Simulate humidity as a random value between 0 and 100
  int humidity = random(40, 90);

  // Serial output -->  조도, 습도, 온도
  Serial.print(lux);
  Serial.print(",");
  Serial.print(humidity);
  Serial.print(",");
  Serial.println(tempC);
  delay(1000);
}

double luminosity(int RawADC0) {
  double Vout = RawADC0 * 5.0 / 1023;  
  double lux = (2500 / Vout - 500) / 10;
  return lux;
}