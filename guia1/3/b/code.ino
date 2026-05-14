const int PIN_R   = 9;
const int PIN_G   = 10;
const int PIN_B   = 11;
const int PIN_BTN = 3;
const int PIN_POT = A5;

bool encendido = false;
bool btnPrev   = HIGH;

void setup() {
    pinMode(PIN_R,   OUTPUT);
    pinMode(PIN_G,   OUTPUT);
    pinMode(PIN_B,   OUTPUT);
    pinMode(PIN_BTN, INPUT_PULLUP);
}

void loop() {
  bool btnNow = digitalRead(PIN_BTN);
  if (btnPrev == HIGH && btnNow == LOW) {
        encendido = !encendido;
        delay(50);
  }
    btnPrev = btnNow;
  
  if (!encendido) {
        analogWrite(PIN_R, 0);
        analogWrite(PIN_G, 0);
        analogWrite(PIN_B, 0);
        return;
  }
  
  int pot = analogRead(PIN_POT);
  
  if (pot <= 341) {
        analogWrite(PIN_R, map(pot, 0, 341, 0, 255));
        analogWrite(PIN_G, 0);
        analogWrite(PIN_B, 0);
  }
  else if (pot <= 682) {
        analogWrite(PIN_R, 0);
        analogWrite(PIN_G, map(pot, 342, 682, 0, 255));
        analogWrite(PIN_B, 0);
  }
  else {
        analogWrite(PIN_R, 0);
        analogWrite(PIN_G, 0);
        analogWrite(PIN_B, map(pot, 683, 1023, 0, 255));
  }
}