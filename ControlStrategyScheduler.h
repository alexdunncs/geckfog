#ifndef CONTROLSTRATEGYSCHEDULER
#define CONTROLSTRATEGYSCHEDULER

#include "StrategySchedule.h"
#include "SimpleTime.h"

class ControlStrategyScheduler {
  static const uint8_t MAX_STRATEGY_COUNT = 32;
  StrategySchedule strategySchedules[MAX_STRATEGY_COUNT];
  uint8_t strategyCount = 0;
  uint8_t lastActiveStrategyIdx = 0;
  
  void printNewStrategyMessage();
  StrategySchedule getActiveSchedule(SimpleTime currentTime);

  public:
  void appendStrategyToSchedule(ControlStrategy* strategy, SimpleTime activationTime);
  ControlStrategy* getActiveStrategy();
  void printSchedule();

  ControlStrategyScheduler();
  
};

#endif
