// C++ code
//
#define GREENLED 4
#define YELLOWLED 8
#define REDLED 12

void setup()
{
  pinMode(GREENLED, OUTPUT);
  pinMode(YELLOWLED, OUTPUT);
  pinMode(REDLED, OUTPUT);
}

void loop()
{  
  for (int i = 0; i < 3; i++) 
  {
    digitalWrite(GREENLED, HIGH);
    delay(500);
    digitalWrite(GREENLED, LOW);
    delay(500);
  }
  digitalWrite(GREENLED, HIGH);
  delay(5000);
  digitalWrite(GREENLED, LOW);
  digitalWrite(YELLOWLED, HIGH);
  delay(2000);
  digitalWrite(YELLOWLED, LOW);
  digitalWrite(REDLED, HIGH);
  delay(5000);
  digitalWrite(REDLED, LOW);
}