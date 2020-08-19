#include "StrategySchedule.h"

StrategySchedule::StrategySchedule(ControlStrategy* strategy, unsigned long int duration): strategy(strategy), duration(duration) {}

StrategySchedule::StrategySchedule(): StrategySchedule(nullptr, 0) {}
