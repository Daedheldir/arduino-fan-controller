#pragma once
#include <Arduino.h>

#include <LiquidCrystal_I2C.h>
#include "TimerMillis.h"

namespace dh
{
    class LCDController
    {
    public:
        LCDController();
        bool init();
        void print(int posX, int posY, char message[]);
        void print(int posX, int posY, char message);
        void print(int posX, int posY, int message);
        void clear();
        bool update(int cpuTemp, int cpuRpm, int gpuTemp, int gpuRpm);

    private:
        LiquidCrystal_I2C lcd; // Set the LCD I2C address
        TimerMillis timer;
    };

    //LiquidCrystal_I2C LCDController::lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
    //TimerMillis LCDController::timer(500);
} // namespace dh