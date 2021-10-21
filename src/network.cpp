
#include "network.h"

void connectToWifi() {
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("connecting to Wifi");
    Serial.print(".");
  }
  Serial.println();
}