#include <Arduino.h>


// add this file with const char* ssid and password definitions
#include "secrets.h"

#include "detector.h"
#include "network.h"


detector hausstrom;
detector heizstrom;
detector netz;
detector einspeisung;


const int detector_count = 4;
detector* detectors[detector_count] = {
  &hausstrom, &heizstrom, &netz, &einspeisung
};


void setup() {
  Serial.begin(9600);

  heizstrom = createDetector(D0, "Heizstrom");
  hausstrom = createDetector(D1, "Hausstrom");
  netz = createDetector(D2, "Netz");
  einspeisung = createDetector(D3, "Einspeisung");

  for (int i = 0; i < detector_count; i++) {
    pinMode(detectors[i]->pin, INPUT);
  }
}


void loop() {
  connectToWifi();

  for (int i = 0; i < detector_count; i++) {
    check(detectors[i]);
  }
}
