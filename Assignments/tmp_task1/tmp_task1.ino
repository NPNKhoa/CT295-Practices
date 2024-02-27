#define sensorPin A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(sensorPin);

  float voltage = reading * 5.0 / 1024.0;

  float temp = voltage * 100.0;

  Serial.println(temp);

  delay(1000);
}
