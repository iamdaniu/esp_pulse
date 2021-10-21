
#include "network.h"
#include "log.h"

// add this file with const char* ssid and password definitions
#include "secrets.h"



void connectToWifi() {
  bool tryConnect = !WiFi.isConnected();
  if (tryConnect) {
    WiFi.begin(ssid, password);
    log("connecting to Wifi");
  }
  while (WiFi.status() != WL_CONNECTED) {
    log(".");
    delay(500);
  }
  if (tryConnect) {
    logln("");
    logln("connected to " + String(ssid));
  }
}

void sendPut(const char *url) {
  log("sending put to ");
  logln(url);

  WiFiClient wifiClient;
  HTTPClient httpClient;
  
  int connect = httpClient.begin(wifiClient, url);
  if (connect) {
    int response = httpClient.PUT("This is just a message");
    logln("received back " + String(response));
  } else {
    logln("failed to connect: " + String(connect));
  }

}