const int pot = A5;
const int buzzer = 3;

void setup() {
    pinMode(buzzer, OUTPUT);
}

void loop() {
    int valorPot = analogRead(pot);
    int pwmVal = map(valorPot, 0, 1023, 1, 255);
    analogWrite(buzzer, pwmVal);
}