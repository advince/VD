/*
 VDMQTT.h - manage Mqtt Connection for Vincenzinux Domotics.
  Vincenzinux
  http://www.vincenzinux.com
*/

#ifndef VDEEPROM_h
#define VDEEPROM_h

#include <Arduino.h>
#include <EEPROM.h>

#define VDEEPROM_VERSION 0
#define VDEEPROM_SUBVERSION 1

#define WFLAG 96
#define WSSID_START 0
#define WSSID_END 32
#define WPWD_START 32
#define WPWD_END 96
#define EEPROM_END 97

class VdEEProm {
  private:
    String ssid;
    String pwd;
    byte saved;
  public:
    VdEEProm();
    void initialize();
    String getSsid();
    String getPwd();
    void clearEEprom();
    void setSsid(String ssid);
    void setPwd(String pwd);
    boolean save();
    boolean isSaved();
    String readEEprom(int inizio, int fine);
};

#endif
