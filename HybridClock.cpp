#include "HybridClock.h"
#include "InternetTime.h"

void HybridClock::sync() {
  Serial.print("Syncing time with internet... ");
  this->lastSyncTime = InternetTime::getSimpleTime();
  this->lastSyncAt = millis();
  this->lastSyncTime.print();
  Serial.println("");
}

SimpleTime HybridClock::getTime() {
  if (!this->initialised) {
    this->init();
  }
  
  unsigned long int syncCheckMillis = millis();
  unsigned long int nextSync = this->lastSyncAt + this->syncThreshold;
  
  if (nextSync > lastSyncAt ) {
//    No rollover
    if (syncCheckMillis > nextSync) {
      this->sync();
    }
  } else {
//    Rollover
    if (syncCheckMillis < this->lastSyncAt && syncCheckMillis > nextSync) {
      this->sync();
    }
  }

  unsigned long int millisSinceSync = millis() - this->lastSyncAt; // Rollover-safe
  SimpleTime timeSinceSync = SimpleTime(0, 0, millisSinceSync / 1000);

  return this->lastSyncTime + timeSinceSync;  
}

void HybridClock::init() {
  if (!this->initialised) {
    Serial.print("Initialising HybridClock... ");
    this->sync();
    Serial.println("... Done.");
    this->initialised = true;  
  } else {
    Serial.println("Attempted to initialise a HybridClock which was already initialised.");
  }
}

HybridClock::HybridClock(SimpleTime initTime): lastSyncAt(millis()), lastSyncTime(initTime), initialised(true){}
HybridClock::HybridClock(): lastSyncTime(SimpleTime(0,0,0)), initialised(false){}
