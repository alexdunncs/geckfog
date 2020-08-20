#ifndef DUTYCYCLESTRATEGY
#define DUTYCYCLESTRATEGY

#include "OpenLoopControlStrategy.h"

#include <stdint.h>

class DutyCycleStrategy: public OpenLoopControlStrategy {
  int defaultControlValue = 255;
  int lastControlValue = defaultControlValue;
  
  unsigned long int activationPeriodMilliseconds;
  unsigned long int deactivationPeriodMilliseconds;
  unsigned long int lastOutputChangeAt;

  bool activationPeriodExceeded();
  bool deactivationPeriodExceeded();
  
  public:
  uint8_t getControlValue();
  void reset();

  DutyCycleStrategy(unsigned long int activationPeriodMilliseconds, unsigned long int deactivationPeriodMilliseconds);
};

#endif