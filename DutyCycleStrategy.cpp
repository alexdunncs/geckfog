#include "DutyCycleStrategy.h"

#include <Arduino.h>

bool DutyCycleStrategy::activationPeriodExceeded() {
  return this->lastControlValue != 0 && millis() > (this->lastOutputChangeAt + this->activationPeriodMilliseconds);
}

bool DutyCycleStrategy::deactivationPeriodExceeded() {
  return this->lastControlValue == 0 && millis() > (this->lastOutputChangeAt + this->deactivationPeriodMilliseconds);
}

uint8_t DutyCycleStrategy::getControlValue() {
  if (activationPeriodExceeded()) {
    this->lastControlValue = 0;
    this->lastOutputChangeAt = millis();
    return 0;
  } else if (deactivationPeriodExceeded()) {
    this->lastControlValue = 255;
    this->lastOutputChangeAt = millis();
    return 255;
  } else {
    return this->lastControlValue;
  }
}

void DutyCycleStrategy::reset() {
  this->lastControlValue = this->defaultControlValue;
  this->lastOutputChangeAt = millis();
}

DutyCycleStrategy::DutyCycleStrategy(
    unsigned long int activationPeriodMilliseconds, 
    unsigned long int deactivationPeriodMilliseconds, 
    uint8_t defaultControlValue): 
    activationPeriodMilliseconds(activationPeriodMilliseconds), 
    deactivationPeriodMilliseconds(deactivationPeriodMilliseconds), 
    defaultControlValue(defaultControlValue),
    lastControlValue(defaultControlValue),
    lastOutputChangeAt(millis()) {
      String name = "DutyCycleStrategy (";
      name.concat(activationPeriodMilliseconds);
      name.concat("/");
      name.concat(deactivationPeriodMilliseconds);
      name.concat(")");
  this->strategyName = name;
}

DutyCycleStrategy::DutyCycleStrategy(
    unsigned long int activationPeriodMilliseconds, 
    unsigned long int deactivationPeriodMilliseconds): 
    DutyCycleStrategy(activationPeriodMilliseconds, deactivationPeriodMilliseconds, 255){}
