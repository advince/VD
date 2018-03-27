/*
  VDLCD162.h - manage LCD SDA A4 SCL A5 for Vincenzinux Domotics.
  Vincenzinux
  http://www.vincenzinux.com
*/

#ifndef VDLCD162_h
#define VDLCD162_h

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define VDLCD162_VERSION 0
#define VDLCD162_SUBVERSION 1

class VdLcd162 {
  private:
    LiquidCrystal_I2C* lcd;
  public:
    VdLcd162();
    VdLcd162(int address);
    void initialize();
    String setMsg(int x,int y,char* msg, int len);
    void clear();
    void clear(int x,int y,int len);
};

#endif
