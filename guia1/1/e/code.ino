const int redPin1   = 7;
const int greenPin1 = 6;
const int bluePin1  = 5;

const int redPin2   = 4;
const int greenPin2 = 3;
const int bluePin2  = 2;

void setup() {
  pinMode(redPin1,   OUTPUT);
  pinMode(greenPin1, OUTPUT);
  pinMode(bluePin1,  OUTPUT);
  pinMode(redPin2,   OUTPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(bluePin2,  OUTPUT);
}

void loop() {
  setColor2(0, 0, 0);

  setColor1(1, 0, 0);  delay(1000);
  setColor1(0, 1, 1);  delay(1000);
  setColor1(0, 1, 0);  delay(1000);
  setColor1(1, 0, 1);  delay(1000);
  setColor1(0, 0, 1);  delay(1000);
  setColor1(1, 1, 1);  delay(1000);
  setColor1(1, 1, 0);  delay(1000);

  setColor1(0, 0, 0);

  setColor2(1, 0, 0);  delay(1000);
  setColor2(0, 1, 1);  delay(1000);
  setColor2(0, 1, 0);  delay(1000);
  setColor2(1, 0, 1);  delay(1000);
  setColor2(0, 0, 1);  delay(1000);
  setColor2(1, 1, 1);  delay(1000);
  setColor2(1, 1, 0);  delay(1000);
}

void setColor1(int r, int g, int b) {
  digitalWrite(redPin1,   r);
  digitalWrite(greenPin1, g);
  digitalWrite(bluePin1,  b);
}

void setColor2(int r, int g, int b) {
  digitalWrite(redPin2,   r);
  digitalWrite(greenPin2, g);
  digitalWrite(bluePin2,  b);
}