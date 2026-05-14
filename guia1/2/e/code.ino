const int pot1 = A5;
const int pot2 = A4;
const int pot3 = A3;

const int redPin   = 9;
const int bluePin  = 10;
const int greenPin = 11;

void setup() {
    pinMode(redPin,   OUTPUT);
    pinMode(bluePin,  OUTPUT);
    pinMode(greenPin, OUTPUT);
}

void loop() {
    int redVal   = map(analogRead(pot1), 0, 1023, 0, 255);
    int blueVal  = map(analogRead(pot2), 0, 1023, 0, 255);
    int greenVal = map(analogRead(pot3), 0, 1023, 0, 255);

    analogWrite(redPin,   redVal);
    analogWrite(bluePin,  blueVal);
    analogWrite(greenPin, greenVal);
}