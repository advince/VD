#include <VDEEPROM.h>

VdEEProm vdEEProm;

void setup() {
  Serial.begin(115200);
  vdEEProm.setSsid("SSID");
  vdEEProm.setPwd("Password");
  vdEEProm.save();
  vdEEProm.initialize();
  if(vdEEProm.isSaved()){
    Serial.print("SSID:");
    Serial.println(vdEEProm.getSsid());
    Serial.print("Password:");
    Serial.println(vdEEProm.getPwd());  
  }
}

void loop() {}

