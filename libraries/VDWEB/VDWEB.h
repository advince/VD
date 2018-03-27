/*
 VDMQTT.h - manage Mqtt Connection for Vincenzinux Domotics.
  Vincenzinux
  http://www.vincenzinux.com
*/

#ifndef VDWEB_h
#define VDWEB_h

#include <Arduino.h>
#include <ESP8266WebServer.h>
#include <VDEEPROM.h>

#define VDWEB_VERSION 0
#define VDWEB_SUBVERSION 1

#define SOFTAPWEB 1
#define WEB 0

class VdWeb {
  private:
    ESP8266WebServer server;
    VdEEProm vdEEProm;
  public:
    VdWeb();
    void loop();
    void launchWeb(int webtype);
    void createWebServer(int webtype);
    void handleRoot(void*thisPtr);
};

#endif
