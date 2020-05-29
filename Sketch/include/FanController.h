#pragma once
#include <Arduino.h>
#include "RPMCounter.h"

namespace dh
{
  class FanController
  {
  public:
    FanController(int pinInterrupt, int pinPwm);
    void init();
    void update(uint8_t temp);

    int getRpm();

    void interrupt();

    int getPinInterrupt();

  private:
    int pinPwm;
    float pwmSignal = 0.0f;
    RPMCounter rpmCounter;

    uint8_t minTemp = 40;
    uint8_t midTemp = 80;
  }; // namespace dh
} // namespace dh
