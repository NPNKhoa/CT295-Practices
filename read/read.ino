// C++ code
//
#define GREENLED 4
#define BLUELED 8
#define REDLED 12

int input;

void setup()
{
  Serial.begin(9600);
  pinMode(GREENLED, OUTPUT);
  pinMode(BLUELED, OUTPUT);
  pinMode(REDLED, OUTPUT);
}

void loop()
{  
  if (Serial.available() > 0) {
    input = Serial.read();

    if (input == 114) {
      digitalWrite(GREENLED, LOW);
      digitalWrite(BLUELED, LOW);
      digitalWrite(REDLED, HIGH);
    }

    if (input == 103) {
      digitalWrite(REDLED, LOW);
      digitalWrite(BLUELED, LOW);
      digitalWrite(GREENLED, HIGH);
    }

    if (input == 98) {
      digitalWrite(GREENLED, LOW);
      digitalWrite(REDLED, LOW);
      digitalWrite(BLUELED, HIGH);
    }

    delay(100);
  }
}