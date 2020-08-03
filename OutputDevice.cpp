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

String OutputDevice::getName() {
  return this->name;
}

OutputDevice::OutputDevice(uint8_t pin): pin(pin), name("unnamed-device") {
  pinMode(this->pin, OUTPUT);
}

OutputDevice::OutputDevice(uint8_t pin, String name): pin(pin), name(name){
  pinMode(this->pin, OUTPUT);
}
