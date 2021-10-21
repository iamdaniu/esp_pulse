
#include "detector.h"

detector createDetector(int pin, const char* name) {
  detector result;
  result.pin = pin;
  result.state = LOW;
  result.name = name;
  return result;  
}

bool hasFlashed(detector* strom){
  int signal = digitalRead(strom->pin);
  bool result = false;
  
  if (signal == HIGH && (strom->state == LOW)) {
    result = true;
    strom->state = HIGH;
  } 

  if (signal == LOW) {
    strom->state = LOW;
  }
  return result;
}