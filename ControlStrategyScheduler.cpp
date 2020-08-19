#include "ControlStrategyScheduler.h"

#include <Arduino.h>

void ControlStrategyScheduler::incrementActiveSchedule() {
  this->activeStrategyIdx = (this->activeStrategyIdx + 1) % this->strategyCount;
  this->lastStrategyChange = millis();
  this->nextStrategyChange = this->lastStrategyChange + (this->getActiveSchedule().duration);
  this->printNewStrategyMessage();
  this->getActiveStrategy()->reset();
}

void ControlStrategyScheduler::printNewStrategyMessage() {
    Serial.print("Activated new strategy: ");
    Serial.println(this->strategySchedules[this->activeStrategyIdx].strategy->getName());
}

StrategySchedule ControlStrategyScheduler::getActiveSchedule() {
//  Serial.print("Last: ");
//  Serial.print(this->lastStrategyChange);
//  Serial.print("    Current: ");
//  Serial.print(millis());
//  Serial.print("    Next: ");
//  Serial.println(this->nextStrategyChange);
  
  if (this->nextStrategyChange > this->lastStrategyChange && millis() >= nextStrategyChange) {
    this->incrementActiveSchedule();
  } else if (this->nextStrategyChange < this->lastStrategyChange && millis() < this->lastStrategyChange && millis() > this->nextStrategyChange) {
    this->incrementActiveSchedule();
    this->printNewStrategyMessage();
  }

  return this->strategySchedules[activeStrategyIdx];
}

void ControlStrategyScheduler::appendStrategyToSchedule(ControlStrategy* strategy, unsigned long int duration) {
  StrategySchedule schedule = StrategySchedule(strategy, duration);
  if (this->strategyCount < this->MAX_STRATEGY_COUNT) {   
    this->strategySchedules[this->strategyCount] = schedule;
    this->strategyCount++;
    Serial.print("Added new strategy to schedule: ");
    Serial.println(strategy->getName());
  } else {
    Serial.println("Failed to add stratedy to scheduler: Max strategy count exceeded.");
  }

  if (this->strategyCount == 1) {
    this->nextStrategyChange = millis() + duration;
  }
}

ControlStrategy* ControlStrategyScheduler::getActiveStrategy() {
  if (this->strategyCount > 0) {
    return this->getActiveSchedule().strategy;  
  } else {
    return nullptr;  
  }
  
}

void ControlStrategyScheduler::printSchedule() {
  Serial.println("Yet to implement ControlStrategyScheduler::printSchedule()");
//  float activeHours = this->activeDuration / 1000.0 / 60.0 / 60.0;
//  float inactiveHours = this->inactiveDuration / 1000.0 / 60.0 / 60.0;
//  Serial.print(activeHours);
//  Serial.print("hrs on, ");
//  Serial.print(inactiveHours);
//  Serial.println("hrs off");
  
}

ControlStrategyScheduler::ControlStrategyScheduler() {}
