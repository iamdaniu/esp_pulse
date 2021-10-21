
#ifndef __DETECTOR_H__
#define __DETECTOR_H__

#include <Arduino.h>


struct detector{
  int pin;
  int state;
  const char* name;
};

detector createDetector(int, const char*);
bool hasFlashed(detector*);


#endif