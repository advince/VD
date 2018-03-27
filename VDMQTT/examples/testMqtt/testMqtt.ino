#include <ESP8266WebServer.h>
#include <VDMQTT.h>

VdMqtt vdMqtt;
unsigned long timerMain;
int sequence=0;
ESP8266WebServer server;
void setup() {
  Serial.begin(115200);
  vdMqtt.connectWifi("Infostrada-2.4GHz-E9C825","1306358013063580");
    if (vdMqtt.isConnectedWifi()) {
      vdMqtt.initialize();
      vdMqtt.setCallback(callback);
      return;
    }
    else{
      vdMqtt.setupAP();
      server.on("/", [&]() {
        IPAddress ip = WiFi.softAPIP();
        String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
        String content = "<!DOCTYPE HTML>\r\n<html>Hello from ESP8266 at ";
        content += ipStr;
        content += "<BR>";
        content += vdMqtt.getMacAddress();
        content += "<p>";
        content += vdMqtt.getScannedSsid();
        content += "</p>";
        content += "</html>";
        server.send(200, "text/html", content);
      });
      server.begin(80);
    }
    timerMain=(millis()+5000);
 }

void loop() {
 if (vdMqtt.isConnectedWifi()) {
   vdMqtt.loop();
   if(timerMain<millis()){
     vdMqtt.publish(String(sequence));
     timerMain=(millis()+5000);
     sequence++;
   }
 }else{
   server.handleClient();
 }
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println("");
  
}

