#pragma once
#include <Arduino.h>

namespace dh
{
  class TimerMillis
  {
  public:
    TimerMillis(unsigned int delay_ms);

    bool isReady();

    unsigned int getInterval();

    bool update();
    int getTimeAcc();

  private:
    unsigned int delay_ms = 0;
    unsigned int current_time = 0;
    unsigned int previous_time = 0;
    int timeAccumulator = 0;
  };
} // namespace dh
