#ifndef SOUNDBAR
#define SOUNDBAR

#include <Adafruit_Neopixel.h>

class SoundBar {
  Adafruit_NeoPixel strip;
  unsigned int      n_bars;
  unsigned int      height;
  unsigned int      n_pixels;

  const static unsigned int max_intensity = 1024;

  public:

  // Constructor
  SoundBar(Adafruit_NeoPixel strip, unsigned int n_bars, unsigned int height):
    strip(strip), n_pixels(n_bars*height), n_bars(n_bars), height(height) {};

  void lightAll(unsigned short r, unsigned short g, unsigned short b);
  void clearAll();
  void lightBar(unsigned int bar, unsigned int intensity);
  void clearBar(unsigned int bar);

  // private:
  unsigned int barPixelToStripPixel(unsigned int bar, unsigned int pixel);
  void lightPixel(unsigned int bar, unsigned int pixel, unsigned int r, unsigned int g, unsigned int b);
};

#endif
