#pragma once
#include <Arduino.h>
#include "LCDController.h"
namespace dh
{
    class SerialController
    {
    public:
        SerialController(LCDController *lcd);

        void init();
        void update();
        int getCpuTemp();
        int getGpuTemp();

        void recieveWithDelimit();
        void processRecievedData();

    private:
        LCDController *lcdController;

        int cpuTemp = 0;
        int gpuTemp = 0;
        static const int tempArrSize = 1;

        int cpuTempArr[tempArrSize];
        int cpuTempArrIter = 0;

        int gpuTempArr[tempArrSize];
        int gpuTempArrIter = 0;

        bool newDataRecieved = false;
        static const int bufferSize = 2;
        char buffer[bufferSize];
    };
} // namespace dh
