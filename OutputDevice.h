#ifndef OUTPUTDEVICE
#define OUTPUTDEVICE

#include <stdint.h>

class OutputDevice {
  int pin;

  public:
  void activate();
  void deactivate();
  void setOutput(uint8_t controlValue);

  OutputDevice(uint8_t pin);
};

#endif
