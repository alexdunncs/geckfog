#ifndef DEWMAKERSTRATEGY
#define DEWMAKERSTRATEGY

#include "OpenLoopControlStrategy.h"

#include <stdint.h>

class DewmakerStrategy: public OpenLoopControlStrategy {
  int lastControlValue = 0;
  
  unsigned long int activationPeriodMilliseconds;
  unsigned long int deactivationPeriodMilliseconds;
  unsigned long int lastOutputChangeAt;

  bool activationPeriodExceeded();
  bool deactivationPeriodExceeded();
  
  public:
  uint8_t getControlValue();

  DewmakerStrategy(unsigned long int activationPeriodMilliseconds, unsigned long int deactivationPeriodMilliseconds);
};

#endif
