#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

//Requires installation of the ArduinoJson library - use the Arduino Library Manager

#include "InternetTime.h"
#include "OutputDevice.h"
#include "OutputDeviceController.h"
#include "DewmakerStrategy.h"


#include "pin_config_wemos_d1_mini_pro.h"
#include "secrets.h"

const int HUMIDIFIER_PIN = PIN_D1;

void blink(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
  }
}


OutputDevice humidifier;
DewmakerStrategy humidifierStrategy;
OutputDeviceController humidifierController;


void setup() {
  // initialize pins
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(HUMIDIFIER_PIN, OUTPUT);

  Serial.begin(57600);
  delay(100); // Give sufficient time to initialise.

  humidifier = OutputDevice(HUMIDIFIER_PIN, "Humidifier");
  humidifierStrategy = DewmakerStrategy(15000, 30000);
  humidifierController = OutputDeviceController(humidifier, &humidifierStrategy);
  
//  WiFi.begin(Secret::ssid, Secret::password);
//
//  Serial.println("Connecting to wifi...");
//  while (WiFi.status() != WL_CONNECTED) {  //Wait for the WiFI connection completion
//    delay(500);
//    Serial.println("Waiting for connection");
//  }
//  Serial.println("Connected!");
  Serial.println("Setup Complete!");
}



void loop() {
  humidifierController.proc();

//  Serial.println(InternetTime::getUtcString());
//  digitalWrite(LED_BUILTIN, LOW);
//  digitalWrite(PIN_D1, HIGH);
//  delay(10000);
//  
//  digitalWrite(LED_BUILTIN, HIGH);
//  digitalWrite(PIN_D1, LOW);
//  delay(50000);
}
