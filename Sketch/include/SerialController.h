#pragma once
#include <Arduino.h>

namespace dh
{
    class SerialController
    {
    public:
        SerialController();

        void init();
        void update();
        int getCpuTemp();
        int getGpuTemp();

        void recieveWithDelimit();

    private:
        int cpuTemp = 0;
        int gpuTemp = 0;
        static const int tempArrSize = 1;

        int cpuTempArr[tempArrSize];
        int cpuTempArrIter = 0;

        int gpuTempArr[tempArrSize];
        int gpuTempArrIter = 0;

        bool newData = false;
        static const int bufferSize = 2;
        char buffer[bufferSize];
    };
} // namespace dh
