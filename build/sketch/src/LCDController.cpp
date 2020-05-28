#include "../include/LCDController.h"

namespace dh
{
    LCDController::LCDController() : lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE), timer(500)
    {
    }
    bool LCDController::init()
    {
        lcd.begin(16, 2);
        lcd.backlight();
    }
    // static void LCDController::print(int posX, int posY, char message[])
    // {
    //     lcd.setCursor(posX, posY);
    //     lcd.print(message);
    // }
    // static void LCDController::print(int posX, int posY, char message)
    // {
    //     lcd.setCursor(posX, posY);
    //     lcd.print(message);
    // }
    // static void LCDController::print(int posX, int posY, int message)
    // {
    //     lcd.setCursor(posX, posY);
    //     lcd.print(message);
    // }
    // static void LCDController::clear()
    // {
    //     lcd.clear();
    // }
    bool LCDController::update(int cpuTemp, int cpuRpm, int gpuTemp, int gpuRpm)
    {
        timer.updateTimer();

        if (timer.isReady())
        {

            lcd.setCursor(0, 0);
            //CPU XX*C XXXXRPM
            //GPU XX*C XXXXRPM
            lcd.print("CPU:");
            lcd.print(cpuTemp);
            lcd.print((char)223);
            lcd.print("C ");
            lcd.print(cpuRpm);
            lcd.print("RPM");
            lcd.print("   ");

            lcd.setCursor(0, 1);

            lcd.print("GPU:");
            lcd.print(gpuTemp);
            lcd.print((char)223);
            lcd.print("C ");
            lcd.print(gpuRpm);
            lcd.print("RPM");
            lcd.print("   ");

            return true;
        }
        return false;
    }

    //LiquidCrystal_I2C LCDController::lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
    //TimerMillis LCDController::timer(500);
} // namespace dh