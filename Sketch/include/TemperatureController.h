#pragma once
#include <Arduino.h>

namespace dh
{
    class TemperatureController
    {
    public:
        TemperatureController();
        void init();
        void update(uint8_t cpuTemp, uint8_t gpuTemp);

        uint8_t getCpuTemp();
        uint8_t getGpuTemp();

    private:
        static uint8_t const arrSize = 2;

        uint8_t cpuTempArr[arrSize];
        uint8_t cpuTempArrIter = 0;

        uint8_t gpuTempArr[arrSize];
        uint8_t gpuTempArrIter = 0;
    };
} // namespace dh