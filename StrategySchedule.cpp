#include "StrategySchedule.h"

StrategySchedule::StrategySchedule(ControlStrategy* strategy, SimpleTime activationTime): strategy(strategy), activationTime(activationTime) {}

StrategySchedule::StrategySchedule(): StrategySchedule(nullptr, SimpleTime(0,0,0)) {}
