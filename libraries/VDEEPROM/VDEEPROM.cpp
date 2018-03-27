/*
  VDMQTT.cpp - manage Mqtt Connection for Vincenzinux Domotics.
  Vincenzinux
  http://www.vincenzinux.com
*/

#include "VDEEPROM.h"
#include "Arduino.h"

VdEEProm::VdEEProm() {
  EEPROM.begin(512);
}

void VdEEProm::initialize() {
  saved=EEPROM.read(WFLAG);
  ssid="";
  pwd="";
  if(saved){
    ssid=readEEprom(WSSID_START,WSSID_END);
    pwd=readEEprom(WPWD_START,WPWD_END);
  }
}

String VdEEProm::getSsid() {
  return ssid;
}

String VdEEProm::getPwd() {
  return pwd;
}

void VdEEProm::clearEEprom() {
  saved=0;
  ssid="";
  pwd="";
  for (int i = 0; i < EEPROM_END; ++i) { EEPROM.write(i, 0); }
  EEPROM.commit();
}

void VdEEProm::setSsid(String ssid) {
  this->ssid=ssid;
}

void VdEEProm::setPwd(String pwd) {
  this->pwd=pwd;
}

boolean VdEEProm::save() {
  EEPROM.write(WFLAG,1);
  for (int i = WSSID_START; i < ssid.length(); ++i){
    EEPROM.write(i, ssid[i]);
  }
  for (int i = 0; i < pwd.length(); ++i){
    EEPROM.write(WPWD_START+i, pwd[i]);
  }
  EEPROM.commit();
  saved=1;
  return true;
}

boolean VdEEProm::isSaved() {
  return saved;
}

String  VdEEProm::readEEprom(int inizio, int fine){
    String dato="";
    for (int i = inizio; i < fine; ++i){
      dato += char(EEPROM.read(i));
    }
    return dato;
}
