/*
 VDMQTT.h - manage Mqtt Connection for Vincenzinux Domotics.
  Vincenzinux
  http://www.vincenzinux.com
*/

#ifndef VDMQTT_h
#define VDMQTT_h

#include <Arduino.h>
#include <PubSubClient.h>
#include <ESP8266WiFi.h>

#define VDMQTT_VERSION 0
#define VDMQTT_SUBVERSION 1

#define MBROKER "advince.dynu.net"
#define MPORT 1883

#ifdef ESP8266
#include <functional>
#define VDMQTT_CALLBACK_SIGNATURE std::function<void(char*, uint8_t*, unsigned int)> callback
#else
#define VDMQTT_CALLBACK_SIGNATURE void (*callback)(char*, uint8_t*, unsigned int)
#endif

class VdMqtt {
  private:
    WiFiClient espClient;
    String macAddr;
    VDMQTT_CALLBACK_SIGNATURE;
    PubSubClient client;
  public:
    VdMqtt();
    void initialize();
    VdMqtt& setCallback(VDMQTT_CALLBACK_SIGNATURE);
    boolean publish( String payload);
    void reconnect();
    boolean loop();
    void connectWifi(String ssid,String pwd);
    boolean isConnectedWifi();
    void setupAP();
    String getScannedSsid();
    String getMacAddress();
};

#endif
