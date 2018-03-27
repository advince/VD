/*
  VDLCD162.h - manage LCD SDA A4 SCL A5 for Vincenzinux Domotics.
  Vincenzinux
  http://www.vincenzinux.com
*/

#include "VDLCD162.h"
#include "Arduino.h"

VdLcd162::VdLcd162() {
  lcd =new LiquidCrystal_I2C (0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
}

VdLcd162::VdLcd162(int address) {
  lcd =new LiquidCrystal_I2C (address, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
}

void VdLcd162::initialize() {
  //LiquidCrystal_I2C lcd_init(0x3F);
  //lcd=lcd_init;
  lcd->begin(16,2);
  lcd->backlight();
}


String VdLcd162::setMsg(int x,int y,char* msg, int len){
  lcd->setCursor(x,y);
  for(int i=0;i<len;i++){
    lcd->write(msg[i]);
  }
}

void VdLcd162::clear(){
  lcd->clear();
}

void VdLcd162::clear(int x,int y,int len){
  setMsg(x,y," ",len);
}
