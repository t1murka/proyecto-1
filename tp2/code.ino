#define L1_R 13
#define L1_G 12
#define L1_B 11

#define L2_R 10
#define L2_G 9
#define L2_B 8

#define L3_R 5
#define L3_G 6
#define L3_B 7

#define BUTTON 2
#define BUZZER 3

#define POT_TIME A0
#define POT_R A1
#define POT_G A2
#define POT_B A3

bool isRunning = true;
bool lastButtonState = HIGH;


void setup() {
  pinMode(L1_R, OUTPUT);
  pinMode(L1_G, OUTPUT);
  pinMode(L1_B, OUTPUT);

  pinMode(L2_R, OUTPUT);
  pinMode(L2_G, OUTPUT);
  pinMode(L2_B, OUTPUT);

  pinMode(L3_R, OUTPUT);
  pinMode(L3_G, OUTPUT);
  pinMode(L3_B, OUTPUT);

  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);

  Serial.begin(9600);

  turnOffAll();
}


void turnOffAll() {
  digitalWrite(L1_R, LOW);
  digitalWrite(L1_G, LOW);
  analogWrite(L1_B, 0);

  analogWrite(L2_R, 0);
  analogWrite(L2_G, 0);
  digitalWrite(L2_B, LOW);

  analogWrite(L3_R, 0);
  analogWrite(L3_G, 0);
  digitalWrite(L3_B, LOW);
}


void checkButton() {
  bool currentButtonState = digitalRead(BUTTON);

  if (lastButtonState == HIGH &&
      currentButtonState == LOW) {

    delay(50);

    if (digitalRead(BUTTON) == LOW) {
      isRunning = !isRunning;

      if (isRunning == false) {
        turnOffAll();
        noTone(BUZZER);
      }
    }
  }

  lastButtonState = currentButtonState;
}


int readColor(int potentiometerPin) {
  return analogRead(potentiometerPin) / 4;
}


int readTime() {
  int timeValue = analogRead(POT_TIME) * 3;

  if (timeValue < 10) {
    timeValue = 10;
  }

  if (timeValue > 3000) {
    timeValue = 3000;
  }

  return timeValue;
}


void printData(int timeMs) {
  float timeSeconds = timeMs / 1000.0;

  int redValue = readColor(POT_R);
  int greenValue = readColor(POT_G);
  int blueValue = readColor(POT_B);

  Serial.print("Tiempo: ");
  Serial.println(timeSeconds, 2);

  Serial.print("R:");
  Serial.println(redValue);

  Serial.print("G:");
  Serial.println(greenValue);

  Serial.print("B:");
  Serial.println(blueValue);

  Serial.println();
}


void setLed1(int redValue, int greenValue, int blueValue) {
  if (redValue > 5) {
    digitalWrite(L1_R, HIGH);
  }
  else {
    digitalWrite(L1_R, LOW);
  }

  if (greenValue > 5) {
    digitalWrite(L1_G, HIGH);
  }
  else {
    digitalWrite(L1_G, LOW);
  }

  analogWrite(L1_B, blueValue);
}


void setLed2(int redValue, int greenValue, int blueValue) {
  analogWrite(L2_R, redValue);
  analogWrite(L2_G, greenValue);

  if (blueValue > 5) {
    digitalWrite(L2_B, HIGH);
  }
  else {
    digitalWrite(L2_B, LOW);
  }
}


void setLed3(int redValue, int greenValue, int blueValue) {
  analogWrite(L3_R, redValue);
  analogWrite(L3_G, greenValue);

  if (blueValue > 5) {
    digitalWrite(L3_B, HIGH);
  }
  else {
    digitalWrite(L3_B, LOW);
  }
}


void showColor(int ledNumber) {
  int redValue = readColor(POT_R);
  int greenValue = readColor(POT_G);
  int blueValue = readColor(POT_B);

  turnOffAll();

  if (ledNumber == 1) {
    setLed1(redValue, greenValue, blueValue);
  }
  else if (ledNumber == 2) {
    setLed2(redValue, greenValue, blueValue);
  }
  else if (ledNumber == 3) {
    setLed3(redValue, greenValue, blueValue);
  }
}


void showAllLeds() {
  int redValue = readColor(POT_R);
  int greenValue = readColor(POT_G);
  int blueValue = readColor(POT_B);

  setLed1(redValue, greenValue, blueValue);
  setLed2(redValue, greenValue, blueValue);
  setLed3(redValue, greenValue, blueValue);
}


void smartDelay(int delayTime) {
  int elapsedTime = 0;

  while (elapsedTime < delayTime) {
    checkButton();

    if (isRunning == true) {
      delay(10);
      elapsedTime = elapsedTime + 10;
    }
    else {
      turnOffAll();
      noTone(BUZZER);

      delay(10);

      elapsedTime = 0;
    }
  }
}


void runSequence(int ledNumber) {
  int duration = readTime();
  int elapsedTime = 0;
  int serialTime = 0;

  printData(duration);

  while (elapsedTime < duration) {
    checkButton();

    if (isRunning == true) {
      showColor(ledNumber);

      duration = readTime();

      delay(15);

      elapsedTime = elapsedTime + 15;
      serialTime = serialTime + 15;

      if (serialTime >= 500) {
        printData(duration);
        serialTime = 0;
      }
    }
    else {
      turnOffAll();

      delay(15);

      elapsedTime = 0;
      serialTime = 0;
    }
  }
}


void runTransition() {
  if (isRunning == false) {
    return;
  }

  turnOffAll();

  tone(BUZZER, 1000);
  smartDelay(100);
  noTone(BUZZER);

  for (int i = 0; i < 4; i++) {
    if (isRunning == false) {
      break;
    }

    showAllLeds();
    smartDelay(50);

    turnOffAll();
    smartDelay(50);
  }
}


void loop() {
  runSequence(1);
  runTransition();

  runSequence(2);
  runTransition();

  runSequence(3);
  runTransition();
}