
#ifndef __DETECTOR_H__
#define __DETECTOR_H__

#include <Arduino.h>


struct detector{
  int pin;
  int state;
  String name;
};

detector createDetector(int, String);
int check(detector*);


#endif