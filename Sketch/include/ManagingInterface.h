#pragma once
#include <Arduino.h>

#include "FanController.h"
#include "LCDController.h"
#include "SerialController.h"

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
    FanController fan1_controller;
    FanController fan2_controller;
    LCDController lcdController;
    SerialController serialController;
  };
} // namespace dh
