
#include "VDTOUCHRELE.h"

VdTouchRele::VdTouchRele() {
    this->rele=1;
    this->timer=0;
    this->changed=0;
}
void VdTouchRele::initialize() {
    pinMode(RELEPIN,OUTPUT);
    pinMode(TOUCHPIN,INPUT);
}
String VdTouchRele::state() {
    return String(rele);
}

void VdTouchRele::loop(){
  unsigned long currentMillis = millis();
  if(timer<currentMillis){
   if(!digitalRead(TOUCHPIN)){
       if(rele){
        rele=0;
        digitalWrite(RELEPIN, HIGH);
       }else{
        rele=1;
        digitalWrite(RELEPIN, LOW);
       }
       setChanged(1);
       timer=(millis()+1000);
   }
  }
}

String VdTouchRele::setChanged(byte state){
  this->changed=state;
}

byte VdTouchRele::isChanged(){
  return changed;
}

void VdTouchRele::callback(char* topic, byte* payload, unsigned int length,String macAddr) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
  if(String(topic)==macAddr){
    // Switch on the LED if an 1 was received as first character
    if ((char)payload[0] == '1') {
      rele=1;
      digitalWrite(RELEPIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
      // but actually the LED is on; this is because
      // it is acive low on the ESP-01)
    } else {
      rele=0;
      digitalWrite(RELEPIN, HIGH);  // Turn the LED off by making the voltage HIGH
    }
  }
}
