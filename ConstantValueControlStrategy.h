#ifndef CONSTANTVALUECONTROLSTRATEGY
#define CONSTANTVALUECONTROLSTRATEGY

#include <stdint.h>
#include "ControlStrategy.h"

class ConstantValueControlStrategy: public ControlStrategy {
  uint8_t controlValue;
  
  public:
  uint8_t getControlValue();
  void reset();
  ConstantValueControlStrategy(uint8_t controlValue);
};

#endif
