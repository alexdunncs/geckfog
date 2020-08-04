#ifndef OUTPUTDEVICE
#define OUTPUTDEVICE

#include <stdint.h>
#include <Arduino.h>

class OutputDevice {
  int pin;
  String name;
  uint8_t defaultOutputValue;

  public:
  void activate();
  void deactivate();
  void setOutput(uint8_t controlValue);
  String getName();

  void init();

  OutputDevice(uint8_t pin);
  OutputDevice(uint8_t pin, String name);
  OutputDevice(uint8_t pin, String name, uint8_t defaultOutputValue);
};

#endif
