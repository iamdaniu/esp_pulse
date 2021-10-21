#include <Arduino.h>

struct detector{
  int pin;
  int state;
  String name;
};

detector hausstrom;
detector heizstrom;

int check(detector);
detector createDetector(int, String);

void setup() {
  Serial.begin(9600);

  hausstrom = createDetector(D1, "Hausstrom");
  heizstrom = createDetector(D2, "Heizstrom");

  pinMode(hausstrom.pin,INPUT);
  pinMode(heizstrom.pin,INPUT);

}

detector createDetector(int pin, String name) {
  detector result;
  result.pin = pin;
  result.state = LOW;
  result.name = name;
  return result;  
}

void loop() {

  hausstrom.state = check(hausstrom);
  heizstrom.state = check(heizstrom);
}

int check(detector strom){
  int signal;
  signal = digitalRead(strom.pin);
  
  if (signal == HIGH && (strom.state == LOW)) {
    Serial.println(strom.name);
    strom.state = HIGH;
  } 

  if (signal == LOW) {
    strom.state = LOW;
  }
  return strom.state;
}