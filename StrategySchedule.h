#ifndef STRATEGYSCHEDULE
#define STRATEGYSCHEDULE

#include "ControlStrategy.h"
#include "SimpleTime.h"

struct StrategySchedule {
  ControlStrategy* strategy;
  SimpleTime activationTime;

  StrategySchedule(ControlStrategy* strategy, SimpleTime activationTime);
  StrategySchedule();
};

#endif
