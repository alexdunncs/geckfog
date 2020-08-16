#include "OnOffTimer.h"

#include <Arduino.h>

void OnOffTimer::toggle() {
  this->active = !this->active;
  this->lastToggle = millis();
  this->nextToggle = this->lastToggle + (this->active ? this->activeDuration : this->inactiveDuration);
  Serial.print("Toggling control ");
  Serial.println(this->active ? "ON" : "OFF");
}

bool OnOffTimer::isActive() {

  if (this->nextToggle > this->lastToggle && millis() >= nextToggle) {
    this->toggle();
  } else if (this->nextToggle < this->lastToggle && millis() < this->lastToggle && millis() > this->nextToggle) {
    this->toggle();
  }

  return this->active;
}

OnOffTimer::OnOffTimer(unsigned long int activeDuration, unsigned long int inactiveDuration, bool initiallyActive):
  activeDuration(activeDuration), 
  inactiveDuration(inactiveDuration), 
  active(!initiallyActive) {
  toggle();
}

OnOffTimer::OnOffTimer(unsigned long int activeDuration, unsigned long int inactiveDuration): OnOffTimer(activeDuration, inactiveDuration, true) {}
