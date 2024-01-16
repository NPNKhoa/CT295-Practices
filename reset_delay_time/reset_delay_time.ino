// C++ code
//
#define GREENLED 4

int delayTime = 2000;

void setup()
{
  pinMode(GREENLED, OUTPUT);
}

void loop()
{  
  digitalWrite(GREENLED, HIGH);
  delay(delayTime);
  digitalWrite(GREENLED, LOW);
  delayTime -= 100;
  if(delayTime == 0) {
    delayTime = 2000;
  }
  delay(delayTime);
}