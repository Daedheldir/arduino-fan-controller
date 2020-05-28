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
    void update(int temp);

    int getRpm();

    void interrupt();

    int getPinInterrupt();

  private:
    int pinPwm;
    float pwmSignal = 0.0f;
    RPMCounter rpmCounter;

    int minTemp = 40;
    int midTemp = 80;
  }; // namespace dh
} // namespace dh
