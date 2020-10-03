#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <TimeLib.h>

// Requires installation of the ArduinoJson library and Michael Margolis' Time library - use the Arduino Library Manager
// ESP8266 libraries require installation and activation of ESP8266-family boards, installable from https://arduino.esp8266.com/stable/package_esp8266com_index.json

#include "ConstantValueControlStrategy.h"
#include "ControlStrategyScheduler.h"
#include "DutyCycleStrategy.h"
#include "InternetTime.h"
#include "OutputDevice.h"
#include "OutputDeviceController.h"
#include "SimpleTime.h"


#include "pin_config_wemos_d1_mini_pro.h"
#include "secrets.h" // Define constants 'ssid' and 'password'

const int HUMIDIFIER_PIN = PIN_D1;
const int MISTER_PIN = PIN_D2;

void blink(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
  }
}

OutputDevice humidifier = OutputDevice(HUMIDIFIER_PIN, "Humidifier");
OutputDevice mister = OutputDevice(MISTER_PIN, "Mister");

DutyCycleStrategy heavyDewmakerStrategy = DutyCycleStrategy(5000, 15000);
DutyCycleStrategy dewmakerStrategy = DutyCycleStrategy(5000, 20000);
DutyCycleStrategy humidityMaintenanceStrategy = DutyCycleStrategy(8000, 1000*60*15); //up from 5000 on

DutyCycleStrategy mistingStrategy = DutyCycleStrategy(5000, 1000*10);

ConstantValueControlStrategy onStrategy = ConstantValueControlStrategy(255);
ConstantValueControlStrategy offStrategy = ConstantValueControlStrategy(0);

OutputDeviceController humidifierController = OutputDeviceController(humidifier);
OutputDeviceController misterController = OutputDeviceController(mister);

void setup() {
  // initialize pins
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(57600);
  delay(100); // Give time to initialise.
//    WiFi.begin(Secret::ssid, Secret::password);
//  
//    Serial.println("Connecting to wifi...");
//    while (WiFi.status() != WL_CONNECTED) {  //Wait for the WiFI connection completion
//      delay(500);
//      Serial.println("Waiting for connection");
//    }
//    Serial.println("Connected!");
//
//  // noon start
//  humidifierController.appendStrategy(&humidityMaintenanceStrategy, 1000*60*60*8); //12pm-8pm
//  humidifierController.appendStrategy(&heavyDewmakerStrategy, 1000*60*60*2); //8pm-10pm
//  humidifierController.appendStrategy(&dewmakerStrategy, 1000*60*60*8); //10pm-6am
//  humidifierController.appendStrategy(&offStrategy, 1000*60*60*3); //6am-9am
//  humidifierController.appendStrategy(&humidityMaintenanceStrategy, 1000*60*60*3); //9am-12pm
////  misterController.appendStrategy(&mistingStrategy, 1000*60*60*24);
//
//  
//
//  humidifier.init();
//  mister.init();
//  Serial.println("Setup Complete!");

SimpleTime tMin = SimpleTime(0,0,0);
SimpleTime tMid = SimpleTime(12,0,0);
SimpleTime tMax = SimpleTime(23,59,59);

tMin.print();
tMid.print();
tMax.print();
Serial.println(tMin < tMid ? "PASS" : "FAIL");
Serial.println(tMid < tMax ? "PASS" : "FAIL");
Serial.println(tMax == tMax ? "PASS" : "FAIL");
Serial.println(!(tMin == tMid) ? "PASS" : "FAIL");

tMin = tMin + SimpleTime(0,0,45);
tMin.print();

tMin = tMin + SimpleTime(0,0,45);
tMin.print();

tMin = tMin + SimpleTime(0,45,0);
tMin.print();

tMin = tMin + SimpleTime(0,45,0);
tMin.print();

tMax = tMax + SimpleTime(0,0,1);
tMax.print();




}



void loop() {
//  InternetTime::getUtcString();
//  humidifierController.proc();
//  misterController.proc();
}
