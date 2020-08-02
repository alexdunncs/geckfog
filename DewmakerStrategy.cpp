#include "DewmakerStrategy.h"

#include <Arduino.h>

bool DewmakerStrategy::activationPeriodExceeded() {
  return this->lastControlValue != 0 && millis() > (this->lastOutputChangeAt + this->activationPeriodMilliseconds);
}

bool DewmakerStrategy::deactivationPeriodExceeded() {
  return this->lastControlValue == 0 && millis() > (this->lastOutputChangeAt + this->deactivationPeriodMilliseconds);
}

uint8_t DewmakerStrategy::getControlValue() {
  if (activationPeriodExceeded()) {
    Serial.println("Hum. off");
    this->lastControlValue = 0;
    this->lastOutputChangeAt = millis();
    return 0;
  } else if (deactivationPeriodExceeded()) {
    Serial.println("Hum. on");
    this->lastControlValue = 255;
    this->lastOutputChangeAt = millis();
    return 255;
  } else {
    return this->lastControlValue;
  }
}

DewmakerStrategy::DewmakerStrategy(unsigned long int activationPeriodMilliseconds, unsigned long int deactivationPeriodMilliseconds): activationPeriodMilliseconds(activationPeriodMilliseconds), deactivationPeriodMilliseconds(deactivationPeriodMilliseconds), lastOutputChangeAt(0) {

}
