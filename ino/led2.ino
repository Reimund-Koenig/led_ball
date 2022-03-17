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

bool toggle_fast_change;
bool last_reed;
int last_reed_iter;
// Create a buffer for holding the colors (3 bytes per color).
rgb_color color_red0[NUMPIXELS];
rgb_color color_red1[NUMPIXELS];
rgb_color color_red2[NUMPIXELS];
rgb_color color_red[NUMPIXELS];
rgb_color color_green[NUMPIXELS];
rgb_color color_off[NUMPIXELS];

// Create an object for writing to the LED strip.
APA102<DATAPIN, CLOCKPIN> ledStrip;

// Create a buffer for holding the colors (3 bytes per color).
rgb_color colors[NUMPIXELS];

// Set the brightness to use (the maximum is 31).
const uint8_t brightness = 1;

/* Converts a color from HSV to RGB.
   h is hue, as a number between 0 and 360.
   s is the saturation, as a number between 0 and 255.
   v is the value, as a number between 0 and 255. */
rgb_color hsvToRgb(uint16_t h, uint8_t s, uint8_t v) {
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
void led_setup() {
  toggle_fast_change = true;
  last_reed = false;
  last_reed_iter = 0;
  for (uint16_t i = 0; i < NUMPIXELS; i++) {
    color_red[i] = rgb_color(255, 0, 0);
    color_green[i] = rgb_color(0, 255, 0);
    color_off[i] = rgb_color(0, 0, 0);
    if(i<45) {
      color_red0[i] = rgb_color(255, 0, 0);
      color_red1[i] = rgb_color(0, 0, 0);
      color_red2[i] = rgb_color(0, 0, 0);
    } else if(i<45) {
      color_red0[i] = rgb_color(0, 0, 0);
      color_red1[i] = rgb_color(255, 0, 0);
      color_red2[i] = rgb_color(0, 0, 0);
    } else {
      color_red0[i] = rgb_color(0, 0, 0);
      color_red1[i] = rgb_color(0, 0, 0);
      color_red2[i] = rgb_color(255, 0, 0);
    }
  }
}
void led_run(bool is_reed_contact) {
  // led_rainbow();
  //led_fastChange();
}

void led_show_iter_contact_state(int reed_iteration) {
  if(reed_iteration == last_reed_iter) { return; }
  last_reed_iter = reed_iteration;
  if(reed_iteration == 5) {
    ledStrip.write(color_off, NUMPIXELS, brightness);
  }
  if(reed_iteration == 0) {
    ledStrip.write(color_red0, NUMPIXELS, brightness);
    return;
  } 
  if(reed_iteration == 1) {
    ledStrip.write(color_red1, NUMPIXELS, brightness);
    return;
  } 
  if(reed_iteration == 2) {
    ledStrip.write(color_red2, NUMPIXELS, brightness);
    return;
  } 
}

void led_switch_on_contact_change(bool current_reed) {
  if(last_reed == current_reed) { return; }
  last_reed = current_reed;
  led_show_contact_state(current_reed);
}

void led_rainbow() {
  uint8_t time = millis() >> 4;
  for (uint16_t i = 0; i < NUMPIXELS; i++)
  {
    uint8_t p = time - i * 8;
    colors[i] = hsvToRgb((uint32_t)p * 359 / 256, 255, 255);
  }
  ledStrip.write(colors, NUMPIXELS, brightness);
  delay(10);

}

void led_show_contact_state(bool is_contact_turn_led_on) {
  if(is_contact_turn_led_on) {
    ledStrip.write(color_red, NUMPIXELS, brightness);
  } else {
    ledStrip.write(color_green, NUMPIXELS, 0);
  }
}
void led_fastChange() {
  if (toggle_fast_change) {
    ledStrip.write(color_red, NUMPIXELS, brightness);
  } else {
    ledStrip.write(color_off, NUMPIXELS, brightness);
  }
  toggle_fast_change = !toggle_fast_change;
}
#endif
