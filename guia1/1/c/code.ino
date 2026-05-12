const int LEDS = 10;
const int leds[LEDS] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

void setup() {
  for (int i = 0; i < LEDS; i++) {
        pinMode(leds[i], OUTPUT);
        digitalWrite(leds[i], LOW);
  }
}

void loop() {
    // Encender leds impares
  for (int i = 0; i < LEDS; i += 2) {
        digitalWrite(leds[i], HIGH);
  }
    // Apagar leds pares
  for (int i = 1; i < LEDS; i += 2) {
        digitalWrite(leds[i], LOW);
  }
    delay(500);
  
    // Encender leds pares
  for (int i = 1; i < LEDS; i += 2) {
        digitalWrite(leds[i], HIGH);
  }
    // Apagar LEDs impares
  for (int i = 0; i < LEDS; i += 2) {
        digitalWrite(leds[i], LOW);
  }
    delay(500);
}