#include <BH1750.h>
#include <Wire.h>

BH1750 sensor;
#define RED_LED 12
#define BLUE_LED 8
#define GREEN_LED 7

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  sensor.begin();
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float lux = sensor.readLightLevel();
  Serial.print("lux: ");
  Serial.println(lux);
  if(lux < 0) {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
  }
  else if(lux > 0 && lux <= 1000) {
    digitalWrite(RED_LED, HIGH);
  }
  else if (lux > 1000 && lux <= 5000) {
    digitalWrite(BLUE_LED, HIGH);
  }
  else if (lux > 5000 & lux <= 10000) {
    digitalWrite(GREEN_LED, HIGH);
  }
  else {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BLUE_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);
  }
  delay(1000);
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
}
