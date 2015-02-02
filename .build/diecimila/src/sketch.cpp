#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>
void setup();
void loop();
#line 1 "src/sketch.ino"
//#include <Adafruit_NeoPixel.h>
//#include <avr/power.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(80, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop()
{
  strip.setPixelColor(0, 255, 0, 0);
}
