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

void OutputDevice::init() {
  pinMode(this->pin, OUTPUT);
  this->setOutput(this->defaultOutputValue);
}

OutputDevice::OutputDevice(uint8_t pin): OutputDevice(pin, "unnamed-device", 0) {}

OutputDevice::OutputDevice(uint8_t pin, String name): OutputDevice(pin, name, 0){}

OutputDevice::OutputDevice(uint8_t pin, String name, uint8_t defaultOutputValue): pin(pin), name(name), defaultOutputValue(defaultOutputValue) {}
