#ifndef CONTROLSTRATEGY
#define CONTROLSTRATEGY

#include <stdint.h>

class ControlStrategy {
  uint8_t currentControlValue = 0;
  
  public:
  virtual uint8_t getControlValue() = 0;
};

#endif
