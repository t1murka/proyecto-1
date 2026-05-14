const int LED_VERDE = 2;
const int LED_ROJO  = 3;
const int BUZZER    = 4;

void setup() {
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_ROJO,  OUTPUT);
  pinMode(BUZZER,    OUTPUT);

  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_ROJO,  LOW);
  digitalWrite(BUZZER,    LOW);
}

void loop() {
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_ROJO,  LOW);
  noTone(BUZZER);
  delay(5000);

  digitalWrite(LED_VERDE, LOW);

  for (int i = 0; i < 10; i++) {
    digitalWrite(LED_ROJO, HIGH);
    tone(BUZZER, 1000);
    delay(400);

    digitalWrite(LED_ROJO, LOW);
    noTone(BUZZER);
    delay(400);
  }
}