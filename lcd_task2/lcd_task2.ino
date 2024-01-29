# include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);

  lcd.clear();
}

void loop() {
  lcd.print("Hello World!!!");
  lcd.setCursor(0, 1);
}
