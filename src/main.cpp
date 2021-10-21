#include <Arduino.h>

struct detector{
  int pin;
  int state;
  String name;
};

detector hausstrom;
detector heizstrom;
detector netz;
detector einspeisung;

const int detector_count = 4;

detector* detectors[detector_count] = {
  &hausstrom, &heizstrom, &netz, &einspeisung
};

int check(detector*);
detector createDetector(int, String);

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

detector createDetector(int pin, String name) {
  detector result;
  result.pin = pin;
  result.state = LOW;
  result.name = name;
  return result;  
}

void loop() {
  for (int i = 0; i < detector_count; i++) {
    check(detectors[i]);
  }
}

int check(detector* strom){
  int signal;
  signal = digitalRead(strom->pin);
  
  if (signal == HIGH && (strom->state == LOW)) {
    Serial.println(strom->name);
    strom->state = HIGH;
  } 

  if (signal == LOW) {
    strom->state = LOW;
  }
  return strom->state;
}