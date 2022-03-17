#ifdef MYLED2
/* This example shows how to display a moving rainbow pattern on
   an APA102-based LED strip. */

/* By default, the APA102 library uses pinMode and digitalWrite
   to write to the LEDs, which works on all Arduino-compatible
   boards but might be slow.  If you have a board supported by
   the FastGPIO library and want faster LED updates, then install
   the FastGPIO library and uncomment the next two lines: */
//#include <FastGPIO.h>
//#define APA102_USE_FAST_GPIO
// #include <APA102.h>

bool led2_switch;
// Create a buffer for holding the colors (3 bytes per color).
rgb_color led2_color_red[NUMPIXELS];
rgb_color led2_color_green[NUMPIXELS];

// Create an object for writing to the LED strip.
APA102<DATAPIN, CLOCKPIN> led2_ledStrip;

// Create a buffer for holding the colors (3 bytes per color).
rgb_color led2_colors[NUMPIXELS];

// Set the brightness to use (the maximum is 31).
const uint8_t led2_brightness = 1;

/* Converts a color from HSV to RGB.
   h is hue, as a number between 0 and 360.
   s is the saturation, as a number between 0 and 255.
   v is the value, as a number between 0 and 255. */
rgb_color led2_hsvToRgb(uint16_t h, uint8_t s, uint8_t v) {
  uint8_t f = (h % 60) * 255 / 60;
  uint8_t p = (255 - s) * (uint16_t)v / 255;
  uint8_t q = (255 - f * (uint16_t)s / 255) * (uint16_t)v / 255;
  uint8_t t = (255 - (255 - f) * (uint16_t)s / 255) * (uint16_t)v / 255;
  uint8_t r = 0, g = 0, b = 0;
  switch ((h / 60) % 6) {
    case 0: r = v; g = t; b = p; break;
    case 1: r = q; g = v; b = p; break;
    case 2: r = p; g = v; b = t; break;
    case 3: r = p; g = q; b = v; break;
    case 4: r = t; g = p; b = v; break;
    case 5: r = v; g = p; b = q; break;
  }
  return rgb_color(r, g, b);
}
void led2_setup() {
  led2_switch = true;
  for (uint16_t i = 0; i < NUMPIXELS; i++) {
    led2_color_red[i] = rgb_color(255, 0, 0);
    led2_color_green[i] = rgb_color(0, 255, 0);
  }
}
void led2_run() {
  // led2_rainbow();
  led2_fastChange();
}

void led2_rainbow() {
  uint8_t time = millis() >> 4;
  for (uint16_t i = 0; i < NUMPIXELS; i++)
  {
    uint8_t p = time - i * 8;
    led2_colors[i] = led2_hsvToRgb((uint32_t)p * 359 / 256, 255, 255);
  }
  led2_ledStrip.write(led2_colors, NUMPIXELS, led2_brightness);
  delay(10);

}

void led2_fastChange() {
  if (led2_switch) {
    led2_ledStrip.write(led2_color_red, NUMPIXELS, led2_brightness);
  } else {
    led2_ledStrip.write(led2_color_green, NUMPIXELS, led2_brightness);
  }
  led2_switch = !led2_switch;
}
#endif
