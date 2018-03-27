#include <VDEEPROM.h>

VdEEProm vdEEProm;

void setup() {
  Serial.begin(115200);
  vdEEProm.initialize();
  if(vdEEProm.isSaved()){
    Serial.print("SSID:");
    Serial.println(vdEEProm.getSsid());
    Serial.print("Password:");
    Serial.println(vdEEProm.getPwd());  
    }
}

void loop() {}

