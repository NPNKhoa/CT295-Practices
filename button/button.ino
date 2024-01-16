// C++ code
//
#define GREENLED 4
#define button 8

int counter;

void setup()
{
  pinMode(GREENLED, OUTPUT);
  pinMode(button, INPUT);
}

void loop()
{  
  if (digitalRead(button) == HIGH) {
    digitalWrite(GREENLED, HIGH);
    delay(100);
    digitalWrite(GREENLED, LOW);
    delay(100);
  }
  else {
    digitalWrite(GREENLED, LOW);
  }
  delay(10);
}