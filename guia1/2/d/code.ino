const int pot = A5;

// LED1
const int r1 = 11;
const int b1 = 10;
const int g1 = 9;

// LED2
const int r2 = 6;
const int b2 = 5;
const int g2 = 3;

void setLED1(int r, int g, int b) {
    analogWrite(r1, r);
    analogWrite(g1, g);
    analogWrite(b1, b);
}

void setLED2(int r, int g, int b) {
    analogWrite(r2, r);
    analogWrite(g2, g);
    analogWrite(b2, b);
}

void setup() {
    pinMode(r1, OUTPUT);
    pinMode(g1, OUTPUT);
    pinMode(b1, OUTPUT);
    pinMode(r2, OUTPUT);
    pinMode(g2, OUTPUT);
    pinMode(b2, OUTPUT);
}

void loop() {
    int potVal = analogRead(pot);
    int blinkDelay = map(potVal, 0, 1023, 50, 1000);
  
    setLED1(255, 0, 255);
    setLED2(255, 255, 0);
    delay(blinkDelay);
  
    setLED1(0, 0, 0);
    setLED2(0, 0, 0);
    delay(blinkDelay);
}