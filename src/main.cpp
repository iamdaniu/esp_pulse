#include <Arduino.h>


#include "detector.h"
#include "network.h"
#include "log.h"
#include "secrets.h"

detector hausstrom;
detector heizstrom;
detector netz;
detector einspeisung;

void sendImpulse(detector*);

const int detector_count = 4;
detector* detectors[detector_count] = {
  &hausstrom, &heizstrom, &netz, &einspeisung
};


void setup() {
  initLog();

  hausstrom = createDetector(D0, "Hausstrom");
  heizstrom = createDetector(D1, "Heizstrom");
  netz = createDetector(D5, "Netz");
  einspeisung = createDetector(D6, "Einspeisung");

  for (int i = 0; i < detector_count; i++) {
    pinMode(detectors[i]->pin, INPUT);
  }
}


void loop() {
  connectToWifi();

  for (int i = 0; i < detector_count; i++) {
    if (hasFlashed(detectors[i])) {
      sendImpulse(detectors[i]);
    }
  }
}

void sendImpulse(detector* sendFor) {
  char* url = new char[128];
  sprintf(url, "http://%s:%d/sensor/%s/impulse", targetHost, targetPort, sendFor->name);
  logln(url);
  sendPut(url);
  delete url;
}