// C++ code
//
#define GREENLED 4
#define YELLOWLED 8
#define REDLED 12

#define Deplay5s 5000
#define Deplay2s 2000
#define Deplay5ms 500

void setup()
{
  Serial.begin(9600); 
  pinMode(GREENLED, OUTPUT);
  pinMode(YELLOWLED, OUTPUT);
  pinMode(REDLED, OUTPUT);
}

void isLedOn() {
  if (digitalRead(GREENLED) == HIGH) {
    Serial.println("Advanced Green");
    Serial.println("Green: on");
    Serial.println("Yellow: off");
    Serial.println("Red: off");
  }
  else if (digitalRead(YELLOWLED) == HIGH) {
    Serial.println("Advanced Yellow");
    Serial.println("Green: off");
    Serial.println("Yellow: on");
    Serial.println("Red: off");
  }
  else {
    Serial.println("Advanced Red");
    Serial.println("Green: off");
    Serial.println("Yellow: off");
    Serial.println("Red: on");
  }
}

void loop()
{  
  digitalWrite(GREENLED, HIGH);
  isLedOn();
  delay(Deplay5s);
  digitalWrite(GREENLED, LOW);

  digitalWrite(YELLOWLED, HIGH);
  isLedOn();
  delay(2000);
  digitalWrite(YELLOWLED, LOW);

  digitalWrite(REDLED, HIGH);
  isLedOn();
  delay(Deplay5s);
  digitalWrite(REDLED, LOW);
}