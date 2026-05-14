int leds[5] = {10, 9, 6, 5, 3};
int boton = 11;
int pot = A5;

void setup() {
  for (int i = 0; i < 5; i++) {
        pinMode(leds[i], OUTPUT);
  }
    pinMode(boton, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(boton) == LOW) {
      delay(50);
      int vel = map(analogRead(pot), 0, 1023, 100, 1000);
    
    for (int i = 0; i < 5; i++) {
      digitalWrite(leds[i], HIGH);
      delay(vel);
    }

    for (int i = 0; i < 5; i++) {
      digitalWrite(leds[i], LOW);
      delay(vel);
    }
  }
}