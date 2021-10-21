
#include "detector.h"

detector createDetector(int pin, String name) {
  detector result;
  result.pin = pin;
  result.state = LOW;
  result.name = name;
  return result;  
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