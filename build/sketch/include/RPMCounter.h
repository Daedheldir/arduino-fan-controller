#pragma once
#include <Arduino.h>

#include "TimerMillis.h"
namespace dh
{

  class RPMCounter
  {
  public:
    RPMCounter(int pinInterrupt, int fanDivider, int updateInterval);

    void setupCounter();

    int getPinInterrupt();

    void interrupt();

    int getRpm();

    bool update();

  private:
    int pinInterrupt;
    int current_rpm = 0;
    int fanDivider = 2;
    unsigned int interruptAccumulator = 0;
    TimerMillis timer;
  };
} // namespace dh
