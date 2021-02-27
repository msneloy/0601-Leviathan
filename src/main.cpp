#include <Arduino.h>
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "WAC.h"
const char *ssid = SSID;
const char *password = PW;
//Create WAC.h to store creds
//#define SSID "Wireless Access Point"
//#define PW "Password"

WiFiUDP ntpUDP;

NTPClient timeClient(ntpUDP, "asia.pool.ntp.org", 28800, 60000);

void setup(){
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
}

void loop() {
  timeClient.update();

  Serial.println(timeClient.getFormattedTime());

  delay(1000);
}