#ifdef MYLED3
// Define the array of leds
CRGB ledStrip[NUMPIXELS];
CRGB color_red[NUMPIXELS];
CRGB color_green[NUMPIXELS];
CRGB color_off[NUMPIXELS];

bool switch;

void led_setup() {
  switch = true;
  FastLED.addLeds<APA102, DATAPIN, CLOCKPIN, RGB>(ledStrip, NUMPIXELS);  // BGR ordering is typical
  for (uint16_t i = 0; i < NUMPIXELS; i++) {
    color_red[i] = CRGB::Red;
    color_green[i] = CRGB::Green;
    color_off[i] = CRGB::Black;
  }
}

void led_run() {
  led_fastChange();
}

void led_fastChange() {
  if (switch) {
    ledStrip[22] =  CRGB::Green;
    FastLED.show();
  } else {
    ledStrip[22] =  CRGB::Red;
    FastLED.show();
  }
  switch = !switch;
}
#endif
