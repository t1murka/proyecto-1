#include <Adafruit_NeoPixel.h>

#define FLEX_PIN A0
#define LEDS_PIN 2

#define LEDS_COUNT 6

Adafruit_NeoPixel strip =
  Adafruit_NeoPixel(LEDS_COUNT, LEDS_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  strip.begin();
  strip.setBrightness(80);
  strip.show();

  pinMode(FLEX_PIN, INPUT);
  pinMode(LEDS_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int sensor = analogRead(FLEX_PIN);
  sensor = map(sensor, 59, 256, 180, 0);

  if (sensor > 0 && sensor < 45) {
  	strip.setPixelColor(0, strip.Color(0, 255, 0));
    strip.setPixelColor(1, strip.Color(0, 255, 0));
  	strip.show();
  } else if (sensor > 45 && sensor < 90) {
    strip.setPixelColor(2, strip.Color(0, 0, 255));
    strip.setPixelColor(3, strip.Color(0, 0, 255));
  	strip.show();
  } else if (sensor > 90 && sensor <= 180) {
  	strip.setPixelColor(3, strip.Color(255, 0, 0));
    strip.setPixelColor(4, strip.Color(255, 0, 0));
    strip.setPixelColor(5, strip.Color(255, 0, 0));
  	strip.show();
  } else {
  	strip.setPixelColor(0, strip.Color(0, 0, 0));
    strip.setPixelColor(1, strip.Color(0, 0, 0));
    strip.setPixelColor(2, strip.Color(0, 0, 0));
    strip.setPixelColor(3, strip.Color(0, 0, 0));
    strip.setPixelColor(4, strip.Color(0, 0, 0));
    strip.setPixelColor(5, strip.Color(0, 0, 0));
    strip.show();
  }
  
  delay(100);
}
