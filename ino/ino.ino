
#include <ota.ino>
#include <led.ino>
#include <reed.ino>

#ifndef STASSID
#define STASSID "KOENIG"
#define STAPSK  "Lachen*Lustig-Johanna"
#endif

#define LED_DATA_PIN 11
#define LED_CLOCK_PIN 12
#define REED_SWITCH_PIN 6

const char* ssid = STASSID;
const char* password = STAPSK;

void setup() {
    Serial.begin(115200);
    ota_setup();
    led_setup(LED_DATA_PIN, LED_CLOCK_PIN);
    reed_setup(REED_SWITCH_PIN);

    // BLINK
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    ota_run();
    reed_run();
    led_run();

    //BLINK
     digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);
}
