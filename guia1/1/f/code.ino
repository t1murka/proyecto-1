const int BOTON  = 5;
const int BUZZER = 4;

void setup() {
    pinMode(BOTON,  INPUT_PULLUP);
    pinMode(BUZZER, OUTPUT);
}

void loop() {
  if (digitalRead(BOTON) == LOW) {
        tone(BUZZER, 1500);
        delay(300);
        noTone(BUZZER);
        delay(150);
    
        tone(BUZZER, 800);
        delay(300);
        noTone(BUZZER);
        delay(150);
  } else {
        noTone(BUZZER);
  }
}