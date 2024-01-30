// C++ code
//
#define TOPLED 7

#define MIDFIRSTLED 12
#define MIDSECONDLED 2

#define BOTFIRSTLED 8
#define BOTSECONDLED 4

int input;

void setup()
{
  Serial.begin(9600);
  
  pinMode(TOPLED, OUTPUT);
  
  pinMode(MIDFIRSTLED, OUTPUT);
  pinMode(MIDSECONDLED, OUTPUT);
  
  pinMode(BOTFIRSTLED, OUTPUT);
  pinMode(BOTSECONDLED, OUTPUT);
  
  Serial.println("Instruction:");
  Serial.println("Choose 1 number in [1, 4] to run");
  Serial.println("1. Turn on led form left to right sequentially");
  Serial.println("2. Turn on led form right to left sequentially");
  Serial.println("3. Turn on led form middle to edge");
  Serial.println("4. Turn on led form middle to middle");

  input = 0;
}

void turnOnTopLed()
{
  digitalWrite(TOPLED, HIGH);
}

void turnOffTopLed()
{
  digitalWrite(TOPLED, LOW);
}
  
void turnOnLeftLed()
{
  digitalWrite(MIDFIRSTLED, HIGH);
  digitalWrite(BOTFIRSTLED, HIGH);
}

void turnOnRightLed()
{
  digitalWrite(MIDSECONDLED, HIGH);
  digitalWrite(BOTSECONDLED, HIGH);
}

void turnOffLeftLed()
{
  digitalWrite(MIDFIRSTLED, LOW);
  digitalWrite(BOTFIRSTLED, LOW);
}

void turnOffRightLed()
{
  digitalWrite(MIDSECONDLED, LOW);
  digitalWrite(BOTSECONDLED, LOW);
}

void turnOnMidLed()
{
  digitalWrite(MIDFIRSTLED, HIGH);
  digitalWrite(MIDSECONDLED, HIGH);
}

void turnOffMidLed()
{
  digitalWrite(MIDFIRSTLED, LOW);
  digitalWrite(MIDSECONDLED, LOW);
}

void turnOnBotLed()
{
  digitalWrite(BOTFIRSTLED, HIGH);
  digitalWrite(BOTSECONDLED, HIGH);
}

void turnOffBotLed()
{
  digitalWrite(BOTFIRSTLED, LOW);
  digitalWrite(BOTSECONDLED, LOW);
}

void mode1()
{
  for (int i = 1; i <= 6; i++) {
    turnOnLeftLed();
    delay(500);
    turnOffLeftLed();
    turnOnRightLed();
    delay(500);
    turnOffRightLed(); 
  }
  delay(1000);
}

void mode2()
{
  for (int i = 1; i <= 6; i++) {
    turnOnRightLed();
    delay(500);
    turnOffRightLed();
    turnOnLeftLed();
    delay(500);
    turnOffLeftLed(); 
  }
  delay(1000);
}

void mode3()
{
  for (int i = 1; i <= 6; i++) {
    turnOnTopLed();
    delay(500);
    turnOffTopLed();

    turnOnMidLed();
    delay(500);
    turnOffMidLed();

    turnOnBotLed();
    delay(500);
    turnOffBotLed();
  }
  delay(1000);
}

void mode4()
{
  for (int i = 1; i <= 6; i++) {
    turnOnBotLed();
    delay(500);
    turnOffBotLed();

    turnOnMidLed();
    delay(500);
    turnOffMidLed();

    turnOnTopLed();
    delay(500);
    turnOffTopLed();
  }
  delay(1000);
}

void quit()
{
  turnOffTopLed();
  turnOffLeftLed();
  turnOffRightLed();
}

void loop()
{
  input = Serial.read();
  switch (input)
  {
    case '1':
      mode1();
      break;
    case '2':
      mode2();
      break;
    case '3':
      mode3();
      break;
    case '4':
      mode4();
      break;
  }
}