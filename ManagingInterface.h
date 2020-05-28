#pragma once
#include "FanController.h"
#include "LCDController.h"
#include "SerialController.h"

namespace dh
{
  class ManagingInterface
  {
  public:
    ManagingInterface() : fan1_controller(2, 9), fan2_controller(3, 10)
    {
    }

    ~ManagingInterface()
    {
    }

    void setupManager()
    {
      serialController.init();
      fan1_controller.init();
      fan2_controller.init();
      lcdController.init();
    }

    void updateManager()
    {
      serialController.update();
      int cpuTemp = serialController.getCpuTemp();
      int gpuTemp = serialController.getGpuTemp();

      fan1_controller.update(cpuTemp);

      fan2_controller.update(gpuTemp);

      lcdController.update(cpuTemp, fan1_controller.getRpm(), gpuTemp, fan2_controller.getRpm());
    }

    FanController *getFan1Controller()
    {
      return &fan1_controller;
    }
    FanController *getFan2Controller()
    {
      return &fan2_controller;
    }

    void fan1_interrupt()
    {
      fan1_controller.interrupt();
    }
    void fan2_interrupt()
    {
      fan2_controller.interrupt();
    }

  private:
    FanController fan1_controller;
    FanController fan2_controller;
    LCDController lcdController;
    SerialController serialController;
  };
} // namespace dh
