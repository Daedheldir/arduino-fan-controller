#include "../include/FanController.h"

namespace dh
{
  FanController::FanController(int pinInterrupt, int pinPwm) : rpmCounter(pinInterrupt, 4, 250)
  {
    this->pinPwm = pinPwm;
  }
  void FanController::init()
  {
    pinMode(pinPwm, OUTPUT);
  }
  void FanController::update(uint8_t temp)
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

    rpmCounter.update();
  }

  int FanController::getRpm()
  {
    return rpmCounter.getRpm();
  }

  void FanController::interrupt()
  {
    rpmCounter.interrupt();
  }

  int FanController::getPinInterrupt()
  {
    return rpmCounter.getPinInterrupt();
  }
} // namespace dh
