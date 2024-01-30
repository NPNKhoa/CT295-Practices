# include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensorPin = A0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Hello World!!!");
}

void loop() {
  int reading = analogRead(sensorPin);

  float voltage = reading * 5.0 / 1024.0;

  float temp = voltage * 100.0;
  
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(char(178));
  lcd.print("C");
  delay(1000);
}
