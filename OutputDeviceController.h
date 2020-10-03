#ifndef OUTPUTDEVICECONTROLLER
#define OUTPUTDEVICECONTROLLER

#include "OutputDevice.h"
#include "ControlStrategy.h"
#include "ControlStrategyScheduler.h"
#include "SimpleTime.h"

class OutputDeviceController {
  OutputDevice device;
  ControlStrategyScheduler scheduler;
  uint8_t latestControlValue = 0;
  bool enabled = true;

  void printControlValue();

  public:
  void appendStrategy(ControlStrategy* newStrategy, SimpleTime activationTime);
  void proc();
  void enable();
  void disable(int manualValue);
  void disable();

  OutputDeviceController(OutputDevice &device);
};

#endif
