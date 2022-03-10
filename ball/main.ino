

#ifndef STASSID
#define STASSID "KOENIG"
#define STAPSK  "......."
#endif


void setup() {
  Serial.begin(115200);
  //wlan_begin();
  // randomSeed(analogRead(0));
}


void loop() {
  // wait for WiFi connection
  //if (!wlan_is_connected()) { return; }

}

