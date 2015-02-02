#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>
#include "sound_bar.h"
void setup();
void loop();
#line 1 "src/sketch.ino"
//#include <Adafruit_NeoPixel.h>
//#include <avr/power.h>

//#include "sound_bar.h"

#define PIN 6

int n_pixels            = 80;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(n_pixels, PIN, NEO_GRB + NEO_KHZ800);
SoundBar sound_bar      = SoundBar(strip, 10, 8);

void setup() {
  Serial.begin(9600);
  while (!Serial);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  // Wait for serial input
  // while (Serial.available() <= 0) {
  //   Serial.println("0,0,0");   // send an initial string
  //   delay(300);
  // }
}

void loop()
{
  for(int bar = 0; bar < 10; ++bar)
    sound_bar.lightBar(bar, random(0, 1024));
}
