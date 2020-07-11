#pragma once
#include <Arduino.h>
#include "LCDController.h"
namespace dh
{
    class SerialController
    {
    public:
        SerialController(LCDController *lcdController);

        void init();
        void update();
        uint8_t getCpuTemp();
        uint8_t getGpuTemp();

        bool isNewDataRecieved();
        void isNewDataRecieved(bool state);

        void recieveWithDelimit();
        void processRecievedData();

    private:
        uint8_t cpuTemp = 0;
        uint8_t gpuTemp = 0;

        bool newDataRecieved = false;

        static const uint8_t bufferSize = 2;
        char buffer[bufferSize];

        LCDController *lcdController;
    };
} // namespace dh
