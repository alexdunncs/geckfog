#include "ConstantValueControlStrategy.h"

uint8_t ConstantValueControlStrategy::getControlValue() {
  return this->controlValue;
}

void ConstantValueControlStrategy::reset(){}

ConstantValueControlStrategy::ConstantValueControlStrategy(uint8_t controlValue): controlValue(controlValue) {
  String name = String("Constant-value-");
  name.concat(String(this->controlValue));
  this->strategyName = name;
}
