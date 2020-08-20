#ifndef DUTYCYCLESTRATEGY
#define DUTYCYCLESTRATEGY

#include "OpenLoopControlStrategy.h"

#include <stdint.h>

class DutyCycleStrategy: public OpenLoopControlStrategy {
  uint8_t defaultControlValue;
  uint8_t lastControlValue;
  
  unsigned long int activationPeriodMilliseconds;
  unsigned long int deactivationPeriodMilliseconds;
  unsigned long int lastOutputChangeAt;

  bool activationPeriodExceeded();
  bool deactivationPeriodExceeded();
  
  public:
  uint8_t getControlValue();
  void reset();

  DutyCycleStrategy(unsigned long int activationPeriodMilliseconds, unsigned long int deactivationPeriodMilliseconds, uint8_t defaultControlValue);
  DutyCycleStrategy(unsigned long int activationPeriodMilliseconds, unsigned long int deactivationPeriodMilliseconds);
};

#endif
