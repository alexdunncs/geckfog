#include "DewmakerStrategy.h"

#include <Arduino.h>

bool DewmakerStrategy::activationPeriodExceeded() {
  return this->lastControlValue != 0 && (this->lastOutputChangeAt + this->activationPeriodMilliseconds) > millis();
}

bool DewmakerStrategy::deactivationPeriodExceeded() {
  return this->lastControlValue == 0 && (this->lastOutputChangeAt + this->deactivationPeriodMilliseconds) > millis();
}

uint8_t DewmakerStrategy::getControlValue() {
  if (activationPeriodExceeded()) {
    this->lastControlValue = 0;
    return 0;
  } else if (deactivationPeriodExceeded()) {
    this->lastControlValue = 1;
    return 255;
  } else {
    return this->lastControlValue;
  }
}

DewmakerStrategy::DewmakerStrategy(unsigned long int activationPeriodMilliseconds, unsigned long int deactivationPeriodMilliseconds): activationPeriodMilliseconds(activationPeriodMilliseconds), deactivationPeriodMilliseconds(deactivationPeriodMilliseconds), lastOutputChangeAt(0) {

}
