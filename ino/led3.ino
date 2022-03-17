#ifdef MYLED3
// Define the array of leds
CRGB led3_leds[NUMPIXELS];
CRGB led3_color_red[NUMPIXELS];
CRGB led3_color_green[NUMPIXELS];

bool led3_switch;

void led3_setup() {
  led3_switch = true;
  FastLED.addLeds<APA102, DATAPIN, CLOCKPIN, RGB>(led3_leds, NUMPIXELS);  // BGR ordering is typical
  for (uint16_t i = 0; i < NUMPIXELS; i++) {
    led3_color_red[i] = CRGB::Red;
    led3_color_green[i] = CRGB::Green;
  }
}

void led3_run() {
  led3_fastChange();
}

void led3_fastChange() {
  if (led2_switch) {
    led3_leds[22] =  CRGB::Green;
    FastLED.show();
  } else {
    led3_leds[22] =  CRGB::Red;
    FastLED.show();
  }
  led3_switch = !led3_switch;
}
#endif
