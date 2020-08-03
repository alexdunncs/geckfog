#ifndef OUTPUTDEVICE
#define OUTPUTDEVICE

#include <stdint.h>
#include <Arduino.h>

class OutputDevice {
  int pin;
  String name;

  public:
  void activate();
  void deactivate();
  void setOutput(uint8_t controlValue);
  String getName();

  OutputDevice(uint8_t pin);
  OutputDevice(uint8_t pin, String name);
 
};

#endif
