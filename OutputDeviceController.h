#ifndef OUTPUTDEVICECONTROLLER
#define OUTPUTDEVICECONTROLLER

#include "OutputDevice.h"
#include "ControlStrategy.h"

class OutputDeviceController {
  OutputDevice device;
  ControlStrategy* strategy;
  uint8_t latestControlValue = 0;
  bool enabled;

  void printControlValue();

  public:
  void setStrategy(ControlStrategy &newStrategy);
  void proc();
  void enable();
  void disable(int manualValue);
  void disable();

  OutputDeviceController(OutputDevice &device, ControlStrategy* strategy);
};

#endif
