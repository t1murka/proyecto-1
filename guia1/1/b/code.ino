const int LEDS = 10;
const int leds[LEDS] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

void setup() {
  for (int i = 0; i < LEDS; i++) {
        pinMode(leds[i], OUTPUT);
        digitalWrite(leds[i], LOW);
  }
}

void loop() {
  for (int i = 0; i < LEDS; i++) {
        digitalWrite(leds[i], HIGH);
        delay(300);
  }
  
    delay(500);
  
  for (int i = 0; i < LEDS; i++) {
        digitalWrite(leds[i], LOW);
  }
  
    delay(500);
}