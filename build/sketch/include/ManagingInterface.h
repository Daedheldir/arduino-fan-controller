#pragma once
#include <Arduino.h>

#include "FanController.h"
#include "LCDController.h"
#include "SerialController.h"
#include "TemperatureController.h"

namespace dh
{
  class ManagingInterface
  {
  public:
    ManagingInterface();

    ~ManagingInterface();

    void setupManager();

    void updateManager();

    FanController *getFan1Controller();
    FanController *getFan2Controller();
    void fan1_interrupt();
    void fan2_interrupt();

  private:
    uint8_t cpuTemp = 0;
    uint8_t gpuTemp = 0;
    FanController fan1_controller;
    FanController fan2_controller;
    LCDController lcdController;
    SerialController serialController;
    TemperatureController tempController;
  };
} // namespace dh
