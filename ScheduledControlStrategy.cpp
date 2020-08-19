#include "ScheduledControlStrategy.h"

ScheduledControlStrategy::ScheduledControlStrategy(ControlStrategy* strategy, unsigned long int duration): strategy(strategy), duration(duration) {}
