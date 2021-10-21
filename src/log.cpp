
#include <Arduino.h>

#include "log.h"

void initLog() {
#ifdef SERIAL_OUTPUT
    Serial.begin(9600);
#endif
}

void log(String message) {
#ifdef SERIAL_OUTPUT
    Serial.print(message);
#endif
}

void logln(String message) {
#ifdef SERIAL_OUTPUT
    Serial.println(message);
#endif
}

void log(int num) {
#ifdef SERIAL_OUTPUT
    Serial.print(num);
#endif
}