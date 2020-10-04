#include "OutputDeviceController.h"

#include <Arduino.h>

void OutputDeviceController::printControlValue() {
  Serial.print(this->device.getName());
  Serial.print(" set to ");
  Serial.println(this->latestControlValue);
}

void OutputDeviceController::appendStrategy(ControlStrategy* newStrategy, SimpleTime activationTime) {
  this->scheduler.appendStrategyToSchedule(newStrategy, activationTime);
//  this->proc();
}

void OutputDeviceController::proc() {
  uint8_t previousControlValue = this->latestControlValue;
  ControlStrategy* activeStrategy = this->scheduler.getActiveStrategy();

  if (this->enabled && activeStrategy) { 
//    Serial.print("Got active strategy: ");
//    Serial.println(activeStrategy->getName());
    this->latestControlValue = activeStrategy->getControlValue(); 
//    Serial.print("Got value: ");
//    Serial.println(this->latestControlValue);
  } //else {
//    Serial.println("No strategy is active");
//  }
  
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
//  this->proc();  
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
//  this->proc();
}

void OutputDeviceController::disable() {
  this->disable(0);
}

OutputDeviceController::OutputDeviceController(OutputDevice &device): device(device){}
