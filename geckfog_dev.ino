#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <TimeLib.h>

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

OutputDevice humidifier = OutputDevice(HUMIDIFIER_PIN, "Humidifier");
DewmakerStrategy humidifierStrategy = DewmakerStrategy(15000, 45000);
OutputDeviceController humidifierController = OutputDeviceController(humidifier, &humidifierStrategy);

bool halted = false;

const unsigned long int runtimeLimit = 3 * 60 * 60 * 1000; //Run for three hours
//const unsigned long int runtimeLimit = 2 * 60 * 1000; //Run for two minutes

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

  humidifier.init();
  Serial.println("Setup Complete!");
}



void loop() {
  
  if (millis() < runtimeLimit) {
    humidifierController.proc();
  } else {
    if (!halted) { 
      Serial.println("COMPLETED. HALTING");  
      humidifier.deactivate();
      halted = true;
    }

    // Provide visual indication of halted state
    blink(5);
    delay(1000);
  }
}
