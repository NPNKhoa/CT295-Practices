// C++ code
//
#define TOPBLUELED 8
#define MIDBLUELED 12
#define BOTBLUELED 10

#define TOPREDLED 2
#define MIDREDLED 4
#define BOTREDLED 7

int delayTime = 500;
int input;

void setup()
{
  Serial.begin(9600);
  pinMode(TOPBLUELED, OUTPUT);
  pinMode(MIDBLUELED, OUTPUT);
  pinMode(BOTBLUELED, OUTPUT);

  pinMode(TOPREDLED, OUTPUT);
  pinMode(MIDREDLED, OUTPUT);
  pinMode(BOTREDLED, OUTPUT);
}

// Turn on all led
void turnOnAllLed() {
  turnOnBlueLed();
  turnOnRedLed();
}

// Turn off all led
void turnOffAllLed() {
  turnOffBlueLed();
  turnOffRedLed();
}

// Turn on all blue led
void turnOnBlueLed() {
  digitalWrite(TOPBLUELED, HIGH);
  digitalWrite(MIDBLUELED, HIGH);
  digitalWrite(BOTBLUELED, HIGH);
}

// Turn off all blue led
void turnOffBlueLed() {
  digitalWrite(TOPBLUELED, LOW);
  digitalWrite(MIDBLUELED, LOW);
  digitalWrite(BOTBLUELED, LOW);
}

// Turn on all red led
void turnOnRedLed() {
  digitalWrite(TOPREDLED, HIGH);
  digitalWrite(MIDREDLED, HIGH);
  digitalWrite(BOTREDLED, HIGH);
}

// Turn off all red led
void turnOffRedLed() {
  digitalWrite(TOPREDLED, LOW);
  digitalWrite(MIDREDLED, LOW);
  digitalWrite(BOTREDLED, LOW);
}

// Turn on all bottom led
void turnOnBotLed() {
  digitalWrite(BOTBLUELED, HIGH);
  digitalWrite(BOTREDLED, HIGH);
  delay(delayTime);
}

// Turn on all middle led
void turnOnMidLed() {
  digitalWrite(MIDBLUELED, HIGH);
  digitalWrite(MIDREDLED, HIGH);
  delay(delayTime);
}

// Turn on all top led
void turnOnTopLed() {
  digitalWrite(TOPBLUELED, HIGH);
  digitalWrite(TOPREDLED, HIGH);
  delay(delayTime);
}

// Change speed
void changeSpeed() {
    if (input == 45) {
      delayTime += 100;
    }

    if (delayTime == 0) {
      delayTime = 0;
      return;
    }

    if (input == 43) {
      delayTime -= 100;
    }
}

// Mode 1: Turn on all led and flash 6 times
void mode1() {
  for (int i = 0; i < 7; i++) {
    turnOnAllLed();
    delay(delayTime);
    turnOffAllLed();
    delay(delayTime);

    changeSpeed();
  }
}

// Mode 2: Turn on by color sequentially
void mode2() {
  for (int i = 0; i < 7; i++) {
    turnOnBlueLed();
    delay(delayTime);
    turnOffBlueLed();
    delay(delayTime);

    turnOnRedLed();
    delay(delayTime);
    turnOffRedLed();
    delay(delayTime);

    changeSpeed();
  }
}

// Mode 3: Turn on led by row from bot to top
void mode3() {
  for (int i = 0; i < 7; i++) {
      turnOnBotLed();
      turnOffAllLed();

      turnOnMidLed();
      turnOffAllLed();

      turnOnTopLed();
      turnOffAllLed();

      changeSpeed();
  }
}

// Mode 4: Advance mode 3
void mode4() {
  for (int i = 0; i < 7; i++) {
    turnOnBotLed();
    delay(delayTime);
    turnOnMidLed();
    delay(delayTime);
    turnOnTopLed();
    delay(delayTime);
    turnOffAllLed();
    delay(delayTime);

    changeSpeed();
  }
}

void loop()
{  
  if (Serial.available() > 0) {
    input = Serial.read();

    switch(input) {
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
      case 'q':
        turnOffAllLed();
        break;
    }
  }
}