#include "sound_bar.h"

// Public

void SoundBar::lightAll(unsigned short r, unsigned short g, unsigned short b) {
  for(int i = 0; i < n_pixels; ++i) {
    strip.setPixelColor(i, r, g, b);
  }
  strip.show();
}

void SoundBar::clearAll() {
  for(unsigned int bar = 0; bar < n_bars; ++bar)
    clearBar(bar);
}

void SoundBar::lightBar(unsigned int bar, unsigned int intensity) {
  clearBar(bar);
  unsigned int pixel = round(intensity*1.0/max_intensity * (height - 1));
  for(unsigned int current_pixel = 0; current_pixel <= pixel; ++current_pixel)
    lightPixel(bar, current_pixel, 0, 1, 1);
}

void SoundBar::clearBar(unsigned int bar) {
  for(unsigned int pixel = 0; pixel < height; ++pixel)
    strip.setPixelColor(barPixelToStripPixel(bar, pixel), 0);
  strip.show();
}

// Private

unsigned int SoundBar::barPixelToStripPixel(unsigned int bar, unsigned int pixel) {
  return bar * height + pixel;
}

void SoundBar::lightPixel(
  unsigned int bar,
  unsigned int pixel,
  unsigned int r,
  unsigned int g,
  unsigned int b
) {
  unsigned int strip_pixel = barPixelToStripPixel(bar, pixel);
  strip.setPixelColor(strip_pixel, r, g, b);
  strip.show();
}

