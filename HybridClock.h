#ifndef HYBRIDCLOCK
#define HYBRIDCLOCK

#include <stdint.h>

#include "SimpleTime.h"

// A clock which periodically syncs with internet time and uses millis() for most accesses

class HybridClock {
  const unsigned long int syncThreshold = 1000*60*15; //Sync every 15 minutes
  unsigned long int lastSyncAt = 0;
  SimpleTime lastSyncTime;
  bool initialised = false;

  void sync();

  public:
  SimpleTime getTime();
  void init();

  HybridClock(SimpleTime initTime);
  HybridClock();
};

#endif
