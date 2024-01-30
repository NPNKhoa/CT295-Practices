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
  digitalWrite(GREENLED, HIGH);
  delay(20000);
  digitalWrite(GREENLED, LOW);
  digitalWrite(YELLOWLED, HIGH);
  delay(5000);
  digitalWrite(YELLOWLED, LOW);
  digitalWrite(REDLED, HIGH);
  delay(1000 * 60 * 20);
  digitalWrite(REDLED, LOW);
}