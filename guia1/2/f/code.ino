const int potPin = A5;
const int ledPin = 3;

void setup() {
    pinMode(ledPin, OUTPUT);
}

void loop() {
    int potVal = analogRead(potPin);
    int blinkDelay = map(potVal, 0, 1023, 200, 10000);

    digitalWrite(ledPin, HIGH);
    delay(blinkDelay);
    digitalWrite(ledPin, LOW);
    delay(blinkDelay);
}