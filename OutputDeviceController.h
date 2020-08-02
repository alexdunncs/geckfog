#ifndef OUTPUTDEVICECONTROLLER
#define OUTPUTDEVICECONTROLLER

#include "OutputDevice.h"
#include "ControlStrategy.h"

class OutputDeviceController {
  OutputDevice device;
  ControlStrategy* strategy;

  public:
  void setStrategy(ControlStrategy &newStrategy);
  void proc();

  OutputDeviceController(OutputDevice &device, ControlStrategy* strategy);
};

#endif
