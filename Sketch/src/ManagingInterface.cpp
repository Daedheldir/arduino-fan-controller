#include "../include/ManagingInterface.h"

namespace dh
{
  ManagingInterface::ManagingInterface() : serialController(&lcdController), fan1_controller(2, 9), fan2_controller(3, 10)
  {
  }

  ManagingInterface::~ManagingInterface()
  {
  }

  void ManagingInterface::setupManager()
  {
    serialController.init();
    fan1_controller.init();
    fan2_controller.init();
    lcdController.init();
  }

  void ManagingInterface::updateManager()
  {
    serialController.update();
    int cpuTemp = serialController.getCpuTemp();
    int gpuTemp = serialController.getGpuTemp();

    fan1_controller.update(cpuTemp);

    fan2_controller.update(gpuTemp);

    lcdController.update(cpuTemp, fan1_controller.getRpm(), gpuTemp, fan2_controller.getRpm());
  }

  FanController *ManagingInterface::getFan1Controller()
  {
    return &fan1_controller;
  }
  FanController *ManagingInterface::getFan2Controller()
  {
    return &fan2_controller;
  }

  void ManagingInterface::fan1_interrupt()
  {
    fan1_controller.interrupt();
  }
  void ManagingInterface::fan2_interrupt()
  {
    fan2_controller.interrupt();
  }
} // namespace dh
