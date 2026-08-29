#include <Adafruit_NeoPixel.h>

#define DICE1_PIN 2
#define DICE2_PIN 3
#define BUZZER_PIN 7
#define BUTTON_PIN 8

#define NUM_LEDS 32

Adafruit_NeoPixel dice1(NUM_LEDS, DICE1_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel dice2(NUM_LEDS, DICE2_PIN, NEO_GRB + NEO_KHZ800);

const byte digits[6][8] = {

  // 1
  {
    0b0010,
    0b0010,
    0b0010,
    0b0010,
    0b0010,
    0b0010,
    0b0010,
    0b0000
  },

  // 2
  {
    0b1111,
    0b0001,
    0b0001,
    0b1111,
    0b1000,
    0b1000,
    0b1111,
    0b0000
  },

  // 3
  {
    0b1111,
    0b0001,
    0b0001,
    0b1111,
    0b0001,
    0b0001,
    0b1111,
    0b0000
  },

  // 4
  {
    0b1001,
    0b1001,
    0b1001,
    0b1111,
    0b0001,
    0b0001,
    0b0001,
    0b0000
  },

  // 5
  {
    0b1111,
    0b1000,
    0b1000,
    0b1111,
    0b0001,
    0b0001,
    0b1111,
    0b0000
  },

  // 6
  {
    0b1111,
    0b1000,
    0b1000,
    0b1111,
    0b1001,
    0b1001,
    0b1111,
    0b0000
  }
};

int getPixel(int x, int y) {
  return x * 8 + y;
}

void clearAll() {

  for (int i = 0; i < NUM_LEDS; i++) {
    dice1.setPixelColor(i, 0);
    dice2.setPixelColor(i, 0);
  }

  dice1.show();
  dice2.show();
}

void showNumber(int displayNumber, int number) {

  for (int i = 0; i < NUM_LEDS; i++) {

    if (displayNumber == 1) {
      dice1.setPixelColor(i, 0);
    }
    else {
      dice2.setPixelColor(i, 0);
    }
  }


  int digitIndex = number - 1;


  for (int y = 0; y < 8; y++) {

    for (int x = 0; x < 4; x++) {

      if (bitRead(digits[digitIndex][y], 3 - x)) {

        int pixel = getPixel(x, y);

        if (displayNumber == 1) {

          dice1.setPixelColor(
            pixel,
            dice1.Color(255, 0, 0)
          );

        }
        else {

          dice2.setPixelColor(
            pixel,
            dice2.Color(255, 0, 0)
          );

        }
      }
    }
  }


  if (displayNumber == 1) {
    dice1.show();
  }
  else {
    dice2.show();
  }
}

void allLEDsOn() {

  for (int i = 0; i < NUM_LEDS; i++) {

    dice1.setPixelColor(
      i,
      dice1.Color(255, 0, 0)
    );

    dice2.setPixelColor(
      i,
      dice2.Color(255, 0, 0)
    );
  }

  dice1.show();
  dice2.show();
}

void rollingAnimation() {

  for (int i = 0; i < 15; i++) {

    int random1 = random(1, 7);
    int random2 = random(1, 7);

    showNumber(1, random1);
    showNumber(2, random2);

    delay(50 + i * 10);
  }
}

void winAnimation() {

  for (int i = 0; i < 5; i++) {

    allLEDsOn();

    tone(BUZZER_PIN, 1200);

    delay(200);

    clearAll();

    noTone(BUZZER_PIN);

    delay(200);
  }

  tone(BUZZER_PIN, 1000);
  delay(150);

  tone(BUZZER_PIN, 1500);
  delay(150);

  tone(BUZZER_PIN, 2000);
  delay(300);

  noTone(BUZZER_PIN);
}

void setup() {

  dice1.begin();
  dice2.begin();

  dice1.setBrightness(80);
  dice2.setBrightness(80);

  dice1.show();
  dice2.show();

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  pinMode(BUZZER_PIN, OUTPUT);

  randomSeed(analogRead(A0));


  clearAll();
}

void loop() {

  if (digitalRead(BUTTON_PIN) == LOW) {
    delay(30);

    if (digitalRead(BUTTON_PIN) == LOW) {
      rollingAnimation();

      int diceNumber1 = random(1, 7);
      int diceNumber2 = random(1, 7);

      showNumber(1, diceNumber1);
      showNumber(2, diceNumber2);

      if (diceNumber1 + diceNumber2 == 7) {

        delay(500);

        winAnimation();

        showNumber(1, diceNumber1);
        showNumber(2, diceNumber2);
      }

      while (digitalRead(BUTTON_PIN) == LOW) {
        delay(10);
      }
      delay(30);
    }
  }
}