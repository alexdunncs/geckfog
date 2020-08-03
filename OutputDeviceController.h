#ifndef OUTPUTDEVICECONTROLLER
#define OUTPUTDEVICECONTROLLER

#include "OutputDevice.h"
#include "ControlStrategy.h"

class OutputDeviceController {
  OutputDevice device;
  ControlStrategy* strategy;
  uint8_t latestControlValue = 0;

  void printControlValue();

  public:
  void setStrategy(ControlStrategy &newStrategy);
  void proc();

  OutputDeviceController(OutputDevice &device, ControlStrategy* strategy);
};

#endif
