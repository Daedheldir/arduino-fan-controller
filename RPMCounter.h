#pragma once
#include "TimerMillis.h"
namespace dh
{

  class RPMCounter
  {
  public:
    RPMCounter(int pinInterrupt, int fanDivider, int updateInterval) : timer(updateInterval)
    {
      this->pinInterrupt = pinInterrupt;
      this->fanDivider = fanDivider;
    }

    void setupCounter()
    {
    }

    int getPinInterrupt()
    {
      return pinInterrupt;
    }

    void interrupt()
    {
      interruptAccumulator++;
    }

    int getRpm()
    {
      return current_rpm;
    }

    bool updateCounter()
    {
      timer.updateTimer();
      if (timer.isReady())
      {
        noInterrupts();
        current_rpm = 10 * (interruptAccumulator * 60) / fanDivider;
        interruptAccumulator = 0;
        interrupts();
        return true;
      }
      return false;
    }

  private:
    int pinInterrupt;
    int current_rpm = 0;
    int fanDivider = 2;
    unsigned int interruptAccumulator = 0;
    TimerMillis timer;
  };
} // namespace dh
