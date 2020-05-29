#include "../include/TemperatureController.h"

namespace dh
{

    TemperatureController::TemperatureController()
    {
    }
    void TemperatureController::init()
    {
    }
    void TemperatureController::update(uint8_t cpuTemp, uint8_t gpuTemp)
    {
        if (cpuTemp > 0)
        {
            cpuTempArr[cpuTempArrIter++] = cpuTemp;
            if (cpuTempArrIter >= arrSize)
            {
                cpuTempArrIter = 0;
            }
        }
        if (gpuTemp > 0)
        {
            gpuTempArr[gpuTempArrIter++] = gpuTemp;
            if (gpuTempArrIter >= arrSize)
            {
                gpuTempArrIter = 0;
            }
        }
    }

    uint8_t TemperatureController::getCpuTemp()
    {
        uint8_t tempAverage = 0;

        for (uint8_t i = 0; i < arrSize; ++i)
            tempAverage += cpuTempArr[i];

        tempAverage /= arrSize;
        return tempAverage;
    }
    uint8_t TemperatureController::getGpuTemp()
    {
        uint8_t tempAverage = 0;

        for (uint8_t i = 0; i < arrSize; ++i)
            tempAverage += gpuTempArr[i];

        tempAverage /= arrSize;
        return tempAverage;
    }

} // namespace dh