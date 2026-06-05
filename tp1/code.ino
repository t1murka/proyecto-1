const int red1   = 11;
const int red2   = 10;
const int blue2  = 9;
const int green3 = 5;
const int blue3  = 6;
const int buzzer = 3;

const int ledDelayMs = 1000;

void sound() {
  tone(buzzer, 1000);
  delay(100);
  noTone(buzzer);
}

void setup()
{
  pinMode(red1,   OUTPUT);
  pinMode(red2,   OUTPUT);
  pinMode(blue2,  OUTPUT);
  pinMode(green3, OUTPUT);
  pinMode(blue3,  OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  analogWrite(red1, 255);
  delay(ledDelayMs);
  analogWrite(red1, 0);
  sound();
  
  digitalWrite(red2, HIGH);
  digitalWrite(blue2, HIGH);
  delay(ledDelayMs);
  digitalWrite(red2, LOW);
  digitalWrite(blue2, LOW);
  sound();
  
  analogWrite(green3, 80);
  analogWrite(blue3, 80);
  delay(ledDelayMs);
  analogWrite(green3, 0);
  analogWrite(blue3, 0);
  sound();
}