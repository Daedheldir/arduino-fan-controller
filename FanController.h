#pragma once
#include "RPMCounter.h"
namespace dh
{
  class FanController
  {
  public:
    FanController(int pinInterrupt, int pinPwm) : rpmCounter(pinInterrupt, 4, 250)
    {
      this->pinPwm = pinPwm;
    }
    void init()
    {
      pinMode(pinPwm, OUTPUT);
    }
    void updateController(int temp)
    {
      if (temp < minTemp)
      {
        pwmSignal = 0.f;
      }
      else if (temp < midTemp)
      {
        float x = (static_cast<float>(temp - minTemp) / static_cast<float>(midTemp - minTemp));
        pwmSignal = (1.0f / (1.0f + exp(-(6.0f * (x - 0.3f)))));
      }
      else
      {
        pwmSignal = 1.0f;
      }
      //pwmSignal = 1;
      int speed = static_cast<int>(round(255 * pwmSignal));
      analogWrite(pinPwm, speed);
      rpmCounter.updateCounter();
    }

    int getRpm()
    {
      return rpmCounter.getRpm();
    }

    void interrupt()
    {
      rpmCounter.interrupt();
    }

    int getPinInterrupt()
    {
      return rpmCounter.getPinInterrupt();
    }

  private:
    int pinPwm;
    float pwmSignal = 0.0f;
    RPMCounter rpmCounter;

    int minTemp = 40;
    int midTemp = 80;
  }; // namespace dh
} // namespace dh
