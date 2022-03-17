// Here's how to control the LEDs from any two pins:
#define DATAPIN    13
#define CLOCKPIN   14
#define NUMPIXELS 135 // Number of LEDs in strip
#define REED_SWITCH_PIN 0
#define EMPTY_PIN_BROWN 2

#define MYLED2
#ifdef MYLED1
#include <Adafruit_DotStar.h>
// Because conditional #includes don't work w/Arduino sketches...
#include <SPI.h>         // COMMENT OUT THIS LINE FOR GEMMA OR TRINKET
//#include <avr/power.h> // ENABLE THIS LINE FOR GEMMA OR TRINKET
Adafruit_DotStar strip(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);
#endif
#ifdef MYLED2
//LED 2
//#include <FastGPIO.h>
//#define APA102_USE_FAST_GPIO
#include <APA102.h>
#endif
#ifdef MYLED3
//LED3
#include <FastLED.h>
#endif

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  ota_setup();
  led_setup();
  reed_setup();

  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  ota_run();
  led_show_iter_contact_state(reed_iterate_contact_to_magnet());
  //led_switch_on_contact_change(reed_is_contact_to_magnet());
  //led_fastChange();
}
