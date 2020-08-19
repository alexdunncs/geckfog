#ifndef STRATEGYSCHEDULE
#define STRATEGYSCHEDULE

#include "ControlStrategy.h"

struct StrategySchedule {
  ControlStrategy* strategy;
  unsigned long int duration;

  StrategySchedule(ControlStrategy* strategy, unsigned long int duration);
  StrategySchedule();
};

#endif
