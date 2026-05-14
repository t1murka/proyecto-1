const int redPin   = 11;
const int bluePin  = 10;
const int greenPin = 9;

void setColor(int r, int g, int b) {
    analogWrite(redPin,   r);
    analogWrite(greenPin, g);
    analogWrite(bluePin,  b);
}

void setup()
{
    pinMode(redPin,   OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin,  OUTPUT);
}

void loop()
{
    // cyan
    setColor(0, 80,  80);
    delay(300);
    setColor(0, 160, 160);
    delay(300);
    setColor(0, 255, 255);
    delay(300);
  
    // red
    setColor(80,  0, 0);
    delay(300);
    setColor(160, 0, 0);
    delay(300);
    setColor(255, 0, 0);
    delay(300);
  
    // yellow
    setColor(80,  80,  0);
    delay(300);
    setColor(160, 160, 0);
    delay(300);
    setColor(255, 255, 0);
    delay(300);
}