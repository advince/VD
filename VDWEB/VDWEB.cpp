
#include "VDWEB.h"

VdWeb::VdWeb(){
}

void VdWeb::loop() {
  server.handleClient();
}

void VdWeb::launchWeb(int webtype) {
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("SoftAP IP: ");
  Serial.println(WiFi.softAPIP());
  createWebServer(webtype);
  // Start the server
  server.begin(80);
  Serial.println("Server started");
}

void VdWeb::createWebServer(int webtype){
  if ( webtype == 1 ) {
   server.on("/", [&]() {
        IPAddress ip = WiFi.softAPIP();
        String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
        String content = "<!DOCTYPE HTML>\r\n<html>Hello from ESP8266 at ";
        content += ipStr;
        content += "<p>";
        //content += st;
        content += "</p><form method='get' action='setting'><label>SSID: </label><input name='ssid' length=32><input name='pass' length=64><input type='submit'></form>";
        content += "</html>";
        server.send(200, "text/html", content);
    });
    server.on("/setting", [&]() {
        int statusCode= 404;
        String qsid = server.arg("ssid");
        String qpass = server.arg("pass");
        String content = "{\"Error\":\"404 not found\"}";
        if (qsid.length() > 0 && qpass.length() > 0) {
          vdEEProm.clearEEprom();
          vdEEProm.setSsid(qsid);
          vdEEProm.setPwd(qpass);
          vdEEProm.save();
          content = "{\"Success\":\"saved to eeprom... reset to boot into new wifi\"}";
          statusCode = 200;
        }
        server.send(statusCode, "application/json", content);
    });
  } else if (webtype == 0) {
    server.on("/", [&]() {
      IPAddress ip = WiFi.localIP();
      String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
      server.send(200, "application/json", "{\"IP\":\"" + ipStr + "\"}");
    });
    server.on("/cleareeprom", [&]() {
      String content = "<!DOCTYPE HTML>\r\n<html>";
      content += "<p>Clearing the EEPROM</p></html>";
      server.send(200, "text/html", content);
      Serial.println("clearing eeprom");
      vdEEProm.clearEEprom();
    });
  }
}
