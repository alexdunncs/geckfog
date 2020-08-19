#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <TimeLib.h>

//Requires installation of the ArduinoJson library - use the Arduino Library Manager

#include "InternetTime.h"
#include "OutputDevice.h"
#include "OutputDeviceController.h"
#include "DewmakerStrategy.h"
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
DewmakerStrategy humidifierStrategy = DewmakerStrategy(10000, 30000);
OutputDeviceController humidifierController = OutputDeviceController(humidifier, &humidifierStrategy);
ControlStrategyScheduler scheduler = ControlStrategyScheduler(1000*10, 1000*20);
//ControlStrategyScheduler scheduler = ControlStrategyScheduler(1000*60*60*3, 1000*60*60*9); //on for 3 hours out of every 12 hours

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
  scheduler.printSchedule();
  Serial.println("Setup Complete!");
}



void loop() {

  if (scheduler.isActive()) {
    humidifierController.enable();
  } else {
    humidifierController.disable();
  }
  
}
