#include "OutputDeviceController.h"

#include <Arduino.h>

void OutputDeviceController::printControlValue() {
  Serial.print(this->device.getName());
  Serial.print(" set to ");
  Serial.println(this->latestControlValue);
}

void OutputDeviceController::setStrategy(ControlStrategy &newStrategy) {
  this->strategy = &newStrategy;
  this->proc();
}

void OutputDeviceController::proc() {
  uint8_t previousControlValue = this->latestControlValue;

  if (this->enabled) {
    this->latestControlValue = this->strategy->getControlValue();
  }
  
  this->device.setOutput(this->latestControlValue);
  
  if (this->latestControlValue != previousControlValue) {
    this->printControlValue();
  }
  
}


void OutputDeviceController::enable(){
  if (!this->enabled) {
    Serial.print(this->device.getName());
    Serial.println(" control enabled");
  }
  
  this->enabled = true;
  this->proc();  
}

void OutputDeviceController::disable(int manualValue) {
  if (this->enabled) {
    Serial.print(this->device.getName());
    Serial.print(" control disabled and set to ");
    Serial.println(manualValue);
  }
  
  this->enabled = false;
  this->device.setOutput(manualValue);
  this->latestControlValue = manualValue;
  this->proc();
}

void OutputDeviceController::disable() {
  this->disable(0);
}

OutputDeviceController::OutputDeviceController(OutputDevice &device, ControlStrategy* strategy): device(device), strategy(strategy){
    this->printControlValue();
}
