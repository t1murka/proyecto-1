const int LED1   = 10;
const int LED2   = 9;
const int buzzer = 3;

void setup() {
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
}

void loop() {
  for (int f = 500; f <= 1000; f += 10) {
        tone(buzzer, f);
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, LOW);
        delay(15);
  }
  
  for (int f = 1000; f >= 500; f -= 10) {
        tone(buzzer, f);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);
        delay(15);
  }
}