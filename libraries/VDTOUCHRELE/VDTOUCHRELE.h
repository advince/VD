/*
 VDMQTT.h - manage Mqtt Connection for Vincenzinux Domotics.
  Vincenzinux
  http://www.vincenzinux.com
*/

#ifndef VDTOUCHRELE_h
#define VDTOUCHRELE_h

#include <Arduino.h>


#define VDEEPROM_VERSION 0
#define VDEEPROM_SUBVERSION 1

#define RELEPIN 0
#define TOUCHPIN 2

class VdTouchRele {
  private:
    unsigned long timer;
    byte rele;
    byte changed;
  public:
    VdTouchRele();
    void initialize();
    void loop();
    String state();
    String setChanged(byte state);
    byte isChanged();
    void callback(char* topic, byte* payload, unsigned int length,String macAddr);
};

#endif
