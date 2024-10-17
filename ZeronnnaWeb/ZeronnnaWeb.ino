/*
 * ESP32 Web Server Demo using Accesspoint
 * https://circuits4you.com
 * 21-11-2018
 */
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include "SPIFFS.h"

#include "index.h"  //Web page header file

WebServer server(80);

//Enter your WiFi SSID and PASSWORD
const char* ssid = "Lacie";
const char* password = "Omocron77";

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}

//===============================================================
// Setup
//===============================================================

void setup(void){
  Serial.begin(115200);
  Serial.println();
  Serial.println("Booting Sketch...");

//ESP32 As access point IP: 192.168.4.1
  WiFi.mode(WIFI_AP); //Access Point mode
  WiFi.softAP("ESPWebServer", "12345678");    //Password length minimum 8 char

//Comment below code if you are using Access point only
//ESP32 connects to your wifi -----------------------------------
  // WiFi.mode(WIFI_STA); //Connectto your wifi
  // WiFi.begin(ssid, password);

  // Serial.println("Connecting to ");
  // Serial.print(ssid);

  // //Wait for WiFi to connect
  // while(WiFi.waitForConnectResult() != WL_CONNECTED){      
  //     Serial.print(".");
  //     delay(1000);
  //   }
    
  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
//----------------------------------------------------------------
 
  server.on("/", handleRoot);      //This is display page
 
  server.begin();                  //Start server
  Serial.println("HTTP server started");
}

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void loop(void){
  server.handleClient();
  delay(1);
}