#include <VDLCD162.h>
VdLcd162 vdLcd162(0x3F);

void setup() {
  vdLcd162.initialize();
}

void loop() {
  vdLcd162.setMsg(0,0,"test1",5);
  delay(1000);
  vdLcd162.setMsg(4,0,"2",1);
  delay(1000);
  vdLcd162.clear();
  delay(1000);
  vdLcd162.setMsg(0,0,"test3",5);
  delay(1000);
  vdLcd162.clear(4,0,1);
  vdLcd162.setMsg(0,1,"Finished!",9);
  delay(1000);
}
