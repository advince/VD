/*
  VDMQTT.cpp - manage Mqtt Connection for Vincenzinux Domotics.
  Vincenzinux
  http://www.vincenzinux.com
*/

#include "VDMQTT.h"
#include "Arduino.h"

VdMqtt::VdMqtt() {
    client.setClient(espClient);
}

void VdMqtt::initialize() {
  client.setServer(MBROKER, MPORT);
}

VdMqtt& VdMqtt::setCallback(VDMQTT_CALLBACK_SIGNATURE) {
    client.setCallback(callback);
    return *this;
}

boolean VdMqtt::publish( String payload) {
    return client.publish(macAddr.c_str(),payload.c_str());
}

void VdMqtt::reconnect() {
  Serial.println("mi connetto a mqtt");
  while (!client.connected()) {
    if (client.connect(getMacAddress().c_str())) {
      client.subscribe(macAddr.c_str());
    } else {
    Serial.print("failed, rc=");
    Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void VdMqtt::connectWifi(String ssid,String pwd) {
  WiFi.begin(ssid.c_str(), pwd.c_str());
  Serial.println("Waiting for Wifi to connect");
}

boolean VdMqtt::loop() {
  if (!client.connected()) {
    reconnect();
  }
  return client.loop();
}

boolean VdMqtt::isConnectedWifi() {
  int c = 0;
  while ( c < 20 ) {
    if (WiFi.status() == WL_CONNECTED) {
      return true;
    }
    delay(500);
    c++;
  }
  return false;
}

void VdMqtt::setupAP(void) {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  WiFi.softAP("ESPPROVA","123", 6);
  Serial.println("softap");
 }

String VdMqtt::getScannedSsid(void) {
  String st="";
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0)
    Serial.println("no networks found");
  st = "<ol>";
  for (int i = 0; i < n; ++i)
    {
      st += "<li>";
      st += WiFi.SSID(i);
      st += " (";
      st += WiFi.RSSI(i);
      st += ")";
      st += (WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*";
      st += "</li>";
    }
  st += "</ol>";
  return st;
}

String VdMqtt::getMacAddress(void) {
  unsigned char mac[6];
  WiFi.macAddress(mac);
  for(int i=0;i<6;i++){
    if(String(mac[i],16).length() <2){
      macAddr+="0";
    }
    macAddr+=String(mac[i],16);
    if(i<5){macAddr+=":";}
  }
  Serial.println(macAddr);
  return macAddr;
}
