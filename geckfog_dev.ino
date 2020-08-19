#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <TimeLib.h>

//Requires installation of the ArduinoJson library - use the Arduino Library Manager

#include "InternetTime.h"
#include "OutputDevice.h"
#include "OutputDeviceController.h"
#include "DewmakerStrategy.h"
#include "ConstantValueControlStrategy.h"
#include "ControlStrategyScheduler.h"


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

OutputDevice humidifier = OutputDevice(HUMIDIFIER_PIN, "Humidifier");
DewmakerStrategy dewmakerStrategy = DewmakerStrategy(10000, 30000);
ConstantValueControlStrategy offStrategy = ConstantValueControlStrategy(0);
ConstantValueControlStrategy onStrategy = ConstantValueControlStrategy(255);

OutputDeviceController humidifierController = OutputDeviceController(humidifier);

void setup() {
  // initialize pins
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(57600);
  delay(100); // Give time to initialise.
  //  WiFi.begin(Secret::ssid, Secret::password);
  //
  //  Serial.println("Connecting to wifi...");
  //  while (WiFi.status() != WL_CONNECTED) {  //Wait for the WiFI connection completion
  //    delay(500);
  //    Serial.println("Waiting for connection");
  //  }
  //  Serial.println("Connected!");

  
  humidifierController.appendStrategy(&dewmakerStrategy, 15000);
//  humidifierController.appendStrategy(&onStrategy, 5000);
  humidifierController.appendStrategy(&offStrategy, 30000);

  humidifier.init();
  Serial.println("Setup Complete!");
}



void loop() {
  humidifierController.proc();
}
