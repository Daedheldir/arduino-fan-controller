#include "../include/TimerMillis.h"

namespace dh
{
  TimerMillis::TimerMillis(unsigned int delay_ms)
  {
    this->delay_ms = delay_ms;
    current_time = millis();
    previous_time = current_time;
  }

  bool TimerMillis::isReady()
  {
    if (timeAccumulator < delay_ms)
    {
      return false;
    }
    timeAccumulator -= delay_ms;
    return true;
  }

  unsigned int TimerMillis::getInterval()
  {
    return this->delay_ms;
  }

  bool TimerMillis::updateTimer()
  {
    current_time = millis();
    timeAccumulator += (current_time - previous_time);
    previous_time = current_time;
    return true;
  }
  int TimerMillis::getTimeAcc()
  {
    return timeAccumulator;
  }
} // namespace dh
