#include <Arduino.h>
#include "OutputDevice.h"

void OutputDevice::activate() {
  digitalWrite(this->pin, HIGH);
}

void OutputDevice::deactivate() {
  digitalWrite(this->pin, LOW);
}

void OutputDevice::setOutput(uint8_t controlValue) {
  if (controlValue == 0) {
    this->deactivate();
  } else if (controlValue == 255) {
    this->activate();
  } else {
    analogWrite(this->pin, controlValue);  
  }
}

OutputDevice::OutputDevice(uint8_t pin): pin(pin) {
  pinMode(this->pin, OUTPUT);
}
