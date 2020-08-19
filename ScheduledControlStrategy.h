#ifndef SCHEDULEDCONTROLSTRATEGY
#define SCHEDULEDCONTROLSTRATEGY

#include "ControlStrategy.h"

struct ScheduledControlStrategy {
  ControlStrategy* strategy;
  unsigned long int duration;

  ScheduledControlStrategy(ControlStrategy* strategy, unsigned long int duration);
};

#endif
