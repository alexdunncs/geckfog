#include "OutputDeviceController.h"

void OutputDeviceController::setStrategy(ControlStrategy &newStrategy) {
  this->strategy = &newStrategy;
  this->proc();
}

void OutputDeviceController::proc() {
  this->device.setOutput(this->strategy->getControlValue());
}

OutputDeviceController::OutputDeviceController(OutputDevice &device, ControlStrategy* strategy): device(device), strategy(strategy){
    
}
