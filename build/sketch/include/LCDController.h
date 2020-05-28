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
        // static void print(int posX, int posY, char message[])
        // {
        //     lcd.setCursor(posX, posY);
        //     lcd.print(message);
        // }
        // static void print(int posX, int posY, char message)
        // {
        //     lcd.setCursor(posX, posY);
        //     lcd.print(message);
        // }
        // static void print(int posX, int posY, int message)
        // {
        //     lcd.setCursor(posX, posY);
        //     lcd.print(message);
        // }
        // static void clear()
        // {
        //     lcd.clear();
        // }
        bool update(int cpuTemp, int cpuRpm, int gpuTemp, int gpuRpm);

    private:
        LiquidCrystal_I2C lcd; // Set the LCD I2C address
        TimerMillis timer;
    };

    //LiquidCrystal_I2C LCDController::lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
    //TimerMillis LCDController::timer(500);
} // namespace dh