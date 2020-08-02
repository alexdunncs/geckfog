#ifndef OPENLOOPCONTROLSTRATEGY
#define OPENLOOPCONTROLSTRATEGY

#include <stdint.h>
#include "ControlStrategy.h"

class OpenLoopControlStrategy: public ControlStrategy {
  public:
  virtual uint8_t getControlValue() = 0;
};

#endif
