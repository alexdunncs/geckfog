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
  this->latestControlValue = this->strategy->getControlValue();
  this->device.setOutput(this->latestControlValue);
  
  if (this->latestControlValue != previousControlValue) {
    this->printControlValue();
  }
  
}

OutputDeviceController::OutputDeviceController(OutputDevice &device, ControlStrategy* strategy): device(device), strategy(strategy){
    this->printControlValue();
}
