#ifndef CONTROLSTRATEGYSCHEDULER
#define CONTROLSTRATEGYSCHEDULER

class ControlStrategyScheduler {
  unsigned long int activeDuration;
  unsigned long int inactiveDuration;
  unsigned long int lastToggle = 0;
  unsigned long int nextToggle = 0;
  bool active = false;

  void toggle();

  public:

  bool isActive();
  void printSchedule();

  ControlStrategyScheduler(unsigned long int activeDuration, unsigned long int inactiveDuration);
  ControlStrategyScheduler(unsigned long int activeDuration, unsigned long int inactiveDuration, bool initiallyActive);
  
};

#endif
