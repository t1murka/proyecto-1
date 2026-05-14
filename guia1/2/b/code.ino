const int ledPins[] = {3, 5, 6, 9, 10};
const int brightness[] = {0, 64, 128, 191, 255};

void setup()
{
  for (int i = 0; i < 5; i++) {
        pinMode(ledPins[i], OUTPUT);
  }
}

void loop()
{
  for (int i = 0; i < 5; i++) {
        analogWrite(ledPins[i], brightness[i]);
  }
}