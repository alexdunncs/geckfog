#ifndef CONTROLSTRATEGYSCHEDULER
#define CONTROLSTRATEGYSCHEDULER

#include "StrategySchedule.h"

class ControlStrategyScheduler {
  static const uint8_t MAX_STRATEGY_COUNT = 32;
  StrategySchedule strategySchedules[MAX_STRATEGY_COUNT];
  uint8_t strategyCount = 0;
  uint8_t activeStrategyIdx = 0;
  
  unsigned long int lastStrategyChange = 0;
  unsigned long int nextStrategyChange = 0;
  
  void incrementActiveSchedule();
  void printNewStrategyMessage();
  StrategySchedule getActiveSchedule();

  public:
  void appendStrategyToSchedule(ControlStrategy* strategy, unsigned long int duration);
  ControlStrategy* getActiveStrategy();
  void printSchedule();

  ControlStrategyScheduler();
  
};

#endif
