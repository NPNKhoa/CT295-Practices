// C++ code
//
#define GREENLED 4
#define YELLOWLED 8
#define REDLED 12

int counter;

void setup()
{
  Serial.begin(9600);
  counter = 0;
  pinMode(GREENLED, OUTPUT);
  pinMode(YELLOWLED, OUTPUT);
  pinMode(REDLED, OUTPUT);
}

void loop()
{  
  if (counter <= 100) {
    digitalWrite(GREENLED, HIGH);
    delay(100);
  }
  else if (counter > 100 && counter <= 200) {
    digitalWrite(GREENLED, LOW);
    digitalWrite(YELLOWLED, HIGH);
    delay(100);
  }
  else if (counter > 200 && counter <= 3000) {
    digitalWrite(YELLOWLED, LOW);
    digitalWrite(REDLED, HIGH);
    delay(100);
  }
  else {
    digitalWrite(REDLED, LOW);
    counter = 0;
  }
  counter++;
}