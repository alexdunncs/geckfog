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

DutyCycleStrategy::DutyCycleStrategy(unsigned long int activationPeriodMilliseconds, unsigned long int deactivationPeriodMilliseconds): activationPeriodMilliseconds(activationPeriodMilliseconds), deactivationPeriodMilliseconds(deactivationPeriodMilliseconds), lastOutputChangeAt(0) {
  this->strategyName = "DutyCycleStrategy";
}
