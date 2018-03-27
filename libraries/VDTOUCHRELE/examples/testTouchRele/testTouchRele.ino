#include <VDTOUCHRELE.h>

VdTouchRele vdTouchRele;
unsigned long timerMain=0;

void setup() {
  Serial.begin(115200);
  vdTouchRele.initialize();
}

void loop() {
  if(vdTouchRele.isChanged()){
    Serial.println(vdTouchRele.state());
    vdTouchRele.setChanged(0);
  }
  vdTouchRele.loop();
}


