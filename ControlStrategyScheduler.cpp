#include "ControlStrategyScheduler.h"

#include <Arduino.h>
#include "InternetTime.h"

void ControlStrategyScheduler::printNewStrategyMessage() {
    Serial.print("Activated new strategy: ");
    Serial.println(this->strategySchedules[this->lastActiveStrategyIdx].strategy->getName());
}

StrategySchedule ControlStrategyScheduler::getActiveSchedule(SimpleTime currentTime) {
  const uint8_t lastIdx = this->strategyCount - 1;
  uint8_t activeScheduleIdx;

// Special case of single schedule
 if (this->strategyCount == 0) {
  activeScheduleIdx = lastIdx;
 }
  
//  Special case of latest or earliest schedule active and time rolled over past midnight
  else if ((this->lastActiveStrategyIdx == lastIdx || this->lastActiveStrategyIdx == 0)
      && currentTime < this->strategySchedules[0].activationTime) { 
    activeScheduleIdx = lastIdx;  
  } 
  
//Otherwise, return the latest schedule whose activationTime has passed  
  else {
    activeScheduleIdx = lastIdx;
    for (int i = 0; i < this->strategyCount; i++) {
      if (this->strategySchedules[i].activationTime <= currentTime) {
        activeScheduleIdx = i;
      }
    }
  }

  
  if (activeScheduleIdx != this->lastActiveStrategyIdx) {
    this->lastActiveStrategyIdx = activeScheduleIdx;
    this->printNewStrategyMessage();
  }
  
  return this->strategySchedules[activeScheduleIdx];
}

void ControlStrategyScheduler::appendStrategyToSchedule(ControlStrategy* strategy, SimpleTime activationTime) {
//  CURRENTLY ASSUMES ENTRY IN ASCENDING TIME ORDER
  StrategySchedule schedule = StrategySchedule(strategy, activationTime);
  if (this->strategyCount < this->MAX_STRATEGY_COUNT) {   
    this->strategySchedules[this->strategyCount] = schedule;
    this->strategyCount++;
    Serial.print("Added new strategy to schedule: ");
    Serial.println(strategy->getName());
  } else {
    Serial.println("Failed to add strategy to scheduler: Max strategy count exceeded.");
  }

  if (this->strategyCount == 1) {
    Serial.print("Controller will start up using strategy: ");
    Serial.println(strategy->getName());
  }
}

ControlStrategy* ControlStrategyScheduler::getActiveStrategy() {
  SimpleTime currentTime = this->timeClock.getTime();
  
  if (this->strategyCount > 0) {
    return this->getActiveSchedule(currentTime).strategy;  
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

ControlStrategyScheduler::ControlStrategyScheduler(): timeClock(HybridClock()){}
