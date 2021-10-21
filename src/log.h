
#include <Arduino.h>

#ifndef __LOG_H__
#define __LOG_H__

//#define SERIAL_OUTPUT


void initLog();
void logln(String);
void log(String);
void log(int);

#endif