#include <Adafruit_NeoPixel.h>

const int neopixelPin = 11;
const int buttonPin = 2;
const int potentiometerPin = A5;
const int ledCount = 12;
const int randomPin = A0;

Adafruit_NeoPixel ring =
  Adafruit_NeoPixel(ledCount, neopixelPin, NEO_GRB + NEO_KHZ800);

int effect = 1;

void setup() {
  ring.begin();
  ring.setBrightness(80);
  ring.show();

  pinMode(buttonPin, INPUT_PULLUP);

  randomSeed(analogRead(randomPin));
}

void loop() {
  switch (effect) {
    case 1:
      effect1();
      break;

    case 2:
      effect2();
      break;

    case 3:
      effect3();
      break;
  }
}

void turnOffAll() {
  ring.clear();
  ring.show();
}

int getSpeedTime() {
  int value = analogRead(potentiometerPin);
  int waitTime = map(value, 0, 1023, 100, 900);
  return waitTime;
}

bool waitForButton() {
  int waitTime = getSpeedTime();

  for (int i = 0; i < waitTime / 10; i++) {
    if (digitalRead(buttonPin) == LOW) {
      effect++;

      if (effect > 3) {
        effect = 1;
      }

      turnOffAll();

      while (digitalRead(buttonPin) == LOW) {
        delay(10);
      }

      delay(200);
      return true;
    }

    delay(10);
  }

  return false;
}

void setColor(int led, int color) {
  switch (color) {
    case 1:
      ring.setPixelColor(led, ring.Color(255, 0, 0)); // rojo
      break;

    case 2:
      ring.setPixelColor(led, ring.Color(0, 255, 0)); // verde
      break;

    case 3:
      ring.setPixelColor(led, ring.Color(0, 0, 255)); // azul
      break;

    case 4:
      ring.setPixelColor(led, ring.Color(255, 255, 0)); // amarillo
      break;

    case 5:
      ring.setPixelColor(led, ring.Color(255, 0, 255)); // magenta
      break;

    case 6:
      ring.setPixelColor(led, ring.Color(0, 255, 255)); // cian
      break;

    case 7:
      ring.setPixelColor(led, ring.Color(255, 120, 0)); // naranja
      break;

    case 8:
      ring.setPixelColor(led, ring.Color(255, 255, 255)); // blanco
      break;
  }
}

void effect1() {
  for (int i = 0; i < ledCount; i++) {
    turnOffAll();

    int color = i % 8 + 1;

    setColor(i, color);
    ring.show();

    if (waitForButton()) {
      return;
    }
  }
}

void effect2() {
  for (int i = 0; i < ledCount; i++) {
    turnOffAll();

    setColor(i, 3); // azul
    ring.show();

    if (waitForButton()) {
      return;
    }
  }

  for (int i = ledCount - 1; i >= 0; i--) {
    turnOffAll();

    setColor(i, 1); // rojo
    ring.show();

    if (waitForButton()) {
      return;
    }
  }
}

void effect3() {
  int evenColor = random(1, 9);
  int oddColor = random(1, 9);

  if (evenColor == oddColor) {
    oddColor++;

    if (oddColor > 8) {
      oddColor = 1;
    }
  }

  turnOffAll();

  for (int i = 0; i < ledCount; i = i + 2) {
    setColor(i, evenColor);
  }

  ring.show();

  if (waitForButton()) {
    return;
  }

  turnOffAll();

  if (waitForButton()) {
    return;
  }

  for (int i = 1; i < ledCount; i = i + 2) {
    setColor(i, oddColor);
  }

  ring.show();

  if (waitForButton()) {
    return;
  }

  turnOffAll();

  if (waitForButton()) {
    return;
  }
}