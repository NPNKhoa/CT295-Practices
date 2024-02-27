// C++ code
//
#define GREENLED 4
#define BLUELED 8
#define REDLED 12

int delayTime = 1500;
int input;

bool isTrue = true;

void setup()
{
  Serial.begin(9600);
  pinMode(GREENLED, OUTPUT);
  pinMode(BLUELED, OUTPUT);
  pinMode(REDLED, OUTPUT);
}

void turnOnAllLed() {
  digitalWrite(GREENLED, HIGH);
  digitalWrite(BLUELED, HIGH);
  digitalWrite(REDLED, HIGH);
}

void turnOffAllLed() {
  digitalWrite(GREENLED, LOW);
  digitalWrite(BLUELED, LOW);
  digitalWrite(REDLED, LOW);
}

void changeSpeed() {
    if (input == 45) {
      delayTime += 50;
    }

    if (delayTime == 0) {
      delayTime = 0;
      return;
    }

    if (input == 43) {
      delayTime -= 50;
    }
}

void mode2() {
  while(Serial.available() == 0 && (input != 'q' && input != 101))
  {
    turnOnAllLed();
    delay(delayTime);
    turnOffAllLed();
    delay(delayTime);

    if (Serial.available() > 0) {
      input = Serial.read();
    }

    changeSpeed();

    if (input == 49) {
      turnOnAllLed();
    }

    if (input == 51) {
      mode3();
    }
  }
}

void mode3() {
  while(Serial.available() == 0 && (input != 'q' && input != 101)) {
    digitalWrite(GREENLED, HIGH);
    delay(delayTime);
    digitalWrite(GREENLED, LOW);
    delay(delayTime);
    digitalWrite(BLUELED, HIGH);
    delay(delayTime);
    digitalWrite(BLUELED, LOW);
    delay(delayTime);
    digitalWrite(REDLED, HIGH);
    delay(delayTime);
    digitalWrite(REDLED, LOW);
    delay(delayTime);

    if (Serial.available() > 0) {
      input = Serial.read();
    }

    changeSpeed();

    if (input == 49 || input == 50) break;
  }

  if (input == 49) {
    turnOnAllLed();
  }

  if (input == 50) {
    mode2();
  }
}

void loop()
{  
  if (Serial.available() > 0) {
    input = Serial.read();

    if (input == 49) {
      turnOnAllLed();
    }

    if (input == 50) {
      mode2();
    }

    if (input == 51) {
      mode3();
    }

    if (input == 101 || input == 113) {
      turnOffAllLed();
    }
  }
}