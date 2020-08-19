#ifndef CONTROLSTRATEGY
#define CONTROLSTRATEGY

#include <stdint.h>
#include <Arduino.h>

class ControlStrategy {
  uint8_t currentControlValue = 0;
  
  public:
  String strategyName = "unnamed ControlStrategy";
  virtual uint8_t getControlValue() = 0;
  virtual void reset() = 0;
  String getName();
};

#endif
