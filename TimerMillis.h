#pragma once
namespace dh
{

  class TimerMillis
  {
  public:
    TimerMillis(unsigned int delay_ms)
    {
      this->delay_ms = delay_ms;
      current_time = millis();
      previous_time = current_time;
    }

    bool isReady()
    {
      if (timeAccumulator < delay_ms)
      {
        return false;
      }
      timeAccumulator -= delay_ms;
      return true;
    }

    unsigned int getInterval()
    {
      return this->delay_ms;
    }

    bool updateTimer()
    {
      current_time = millis();
      timeAccumulator += (current_time - previous_time);
      previous_time = current_time;
      return true;
    }
    int getTimeAcc()
    {
      return timeAccumulator;
    }

  private:
    unsigned int delay_ms = 0;
    unsigned int current_time = 0;
    unsigned int previous_time = 0;
    int timeAccumulator = 0;
  };
} // namespace dh
