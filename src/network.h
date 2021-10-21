
#ifndef __NETWORK_H__
#define __NETWORK_H__

#include "ESP8266HTTPClient.h"
#include "ESP8266WiFi.h"

void connectToWifi();
void sendPut(const char *url);

#endif