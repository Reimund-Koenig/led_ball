// Here's how to control the LEDs from any two pins:
#define DATAPIN    13
#define CLOCKPIN   14
#define NUMPIXELS 135 // Number of LEDs in strip
#define REED_SWITCH_PIN 6

void setup() {
  Serial.begin(115200);
  //ota_setup();
  //led_setup();
  //reed_setup(REED_SWITCH_PIN);

  // BLINK
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  //ota_run();
  //reed_run();
  run_led();
}
