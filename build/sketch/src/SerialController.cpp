#include "../include/SerialController.h"

namespace dh
{
    SerialController::SerialController(LCDController *lcdController) : lcdController(lcdController)
    {
    }

    void SerialController::init()
    {
    }
    void SerialController::update()
    {
        if (Serial.available())
        {
            recieveWithDelimit();
            processRecievedData();
        }
    }

    uint8_t SerialController::getCpuTemp()
    {
        return cpuTemp;
    }
    uint8_t SerialController::getGpuTemp()
    {
        return gpuTemp;
    }

    bool SerialController::isNewDataRecieved()
    {
        return newDataRecieved;
    }
    void SerialController::isNewDataRecieved(bool state)
    {
        newDataRecieved = state;
    }

    void SerialController::recieveWithDelimit()
    {
        char recData;

        char startChar = '<';
        char endChar = '>';

        while (Serial.available() > 0 && newDataRecieved == false)
        {
            recData = Serial.read();

            if (recData == startChar)
            {
                Serial.readBytesUntil(endChar, buffer, 3);
                newDataRecieved = true;
            }
        }
        // if (newDataRecieved)
        // {
        //     lcdController->print(0, 0, buffer);
        // }
    }

    void SerialController::processRecievedData()
    {
        //handshake
        if (buffer[0] == 'H' && buffer[1] == 'S')
        {
            Serial.write("<AC>");
        }
        else
        {
            cpuTemp = buffer[0];
            gpuTemp = buffer[1];
        }
    }
} // namespace dh
