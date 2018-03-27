#include <VDEEPROM.h>

VdEEProm vdEEProm;

void setup() {
  Serial.begin(115200);
  vdEEProm.clearEEprom();
  vdEEProm.initialize();
  if(!vdEEProm.isSaved()){
    Serial.print("eeprom Clear");  
  }
}

void loop() {}

