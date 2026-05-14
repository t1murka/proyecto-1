int leds[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int cantidad = 10;
int boton = 3;

void setup() {
  for (int i = 0; i < cantidad; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(boton, INPUT_PULLUP);
}

void pausarSiBoton() {
  while (digitalRead(boton) == LOW) {
    // pausa
  }
}

void loop() {
  for (int i = 0; i < cantidad; i++) {
    pausarSiBoton();
    digitalWrite(leds[i], HIGH);
    delay(200);
  }

  for (int i = 0; i < cantidad; i++) {
    digitalWrite(leds[i], LOW);
  }
  
  delay(200);
}