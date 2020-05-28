#include "../include/RPMCounter.h"

namespace dh
{
  RPMCounter::RPMCounter(int pinInterrupt, int fanDivider, int updateInterval) : timer(updateInterval)
  {
    this->pinInterrupt = pinInterrupt;
    this->fanDivider = fanDivider;
  }

  void RPMCounter::setupCounter()
  {
  }

  int RPMCounter::getPinInterrupt()
  {
    return pinInterrupt;
  }

  void RPMCounter::interrupt()
  {
    interruptAccumulator++;
  }

  int RPMCounter::getRpm()
  {
    return current_rpm;
  }

  bool RPMCounter::updateCounter()
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
} // namespace dh
