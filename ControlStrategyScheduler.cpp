#include "ControlStrategyScheduler.h"

#include <Arduino.h>

void ControlStrategyScheduler::toggle() {
  this->active = !this->active;
  this->lastToggle = millis();
  this->nextToggle = this->lastToggle + (this->active ? this->activeDuration : this->inactiveDuration);
  Serial.print("Toggling control ");
  Serial.println(this->active ? "ON" : "OFF");
}

bool ControlStrategyScheduler::isActive() {

  if (this->nextToggle > this->lastToggle && millis() >= nextToggle) {
    this->toggle();
  } else if (this->nextToggle < this->lastToggle && millis() < this->lastToggle && millis() > this->nextToggle) {
    this->toggle();
  }

  return this->active;
}

void ControlStrategyScheduler::printSchedule() {
  float activeHours = this->activeDuration / 1000.0 / 60.0 / 60.0;
  float inactiveHours = this->inactiveDuration / 1000.0 / 60.0 / 60.0;
  Serial.print(activeHours);
  Serial.print("hrs on, ");
  Serial.print(inactiveHours);
  Serial.println("hrs off");
  
}

ControlStrategyScheduler::ControlStrategyScheduler(unsigned long int activeDuration, unsigned long int inactiveDuration, bool initiallyActive):
  activeDuration(activeDuration), 
  inactiveDuration(inactiveDuration), 
  active(!initiallyActive) {
  toggle();
}

ControlStrategyScheduler::ControlStrategyScheduler(unsigned long int activeDuration, unsigned long int inactiveDuration): ControlStrategyScheduler(activeDuration, inactiveDuration, true) {}
