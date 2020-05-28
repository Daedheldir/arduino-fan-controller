#include "../include/SerialController.h"

namespace dh
{
    SerialController::SerialController(LCDController *lcd) : lcdController(lcd)
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

    int SerialController::getCpuTemp()
    {
        if (tempArrSize <= 1)
            return cpuTemp;

        int tempAverage = 0;

        for (int i = 0; i < tempArrSize; ++i)
            tempAverage += cpuTempArr[i];

        tempAverage /= tempArrSize;
        return tempAverage;
    }
    int SerialController::getGpuTemp()
    {
        if (tempArrSize <= 1)
            return gpuTemp;

        int tempAverage = 0;

        for (int i = 0; i < tempArrSize; ++i)
            tempAverage += gpuTempArr[i];

        tempAverage /= tempArrSize;
        return tempAverage;
    }

    void SerialController::recieveWithDelimit()
    {
        bool recvInProgress = false;

        char startChar = '<';
        char endChar = '>';
        int bufferIter = 0;
        char recData;

        while (Serial.available() > 0 && newDataRecieved == false)
        {
            recData = Serial.read();
            //delay(250);

            if (recData == startChar)
            {
                Serial.readBytesUntil(endChar, buffer, 3);
                newDataRecieved = true;
            }

            /*old bugged recieving method DO NOT TOUCH

            if started recieving
            if (recvInProgress)
            {
                //if recData isn't the endChar
                if (recData != endChar)
                {
                    //set buffer at iter to rec data and increase iter
                    //LCDController::print(14, 0, bufferIter);
                    buffer[bufferIter] = recData;
                    bufferIter++;
                    //if iter is about to overflow go back to max iter size
                    if (bufferIter >= bufferSize)
                        bufferIter = bufferSize - 1;
                }
                //else if recData is the endChar
                else
                {
                    recvInProgress = false;
                    newDataRecieved = true;
                }
            }
            //if we arent recieving and the recData is the startChar
            else if (recData == startChar)
            {
                //set recieving to true and bufferIter to start of the buffer
                recvInProgress = true;
                newDataRecieved = false;
                bufferIter = 0;
            }
            delay(250);
            */
        }
        //Serial.write(recData);
    }
    void SerialController::processRecievedData()
    {
        if (buffer[0] == 'H' && buffer[1] == 'S')
        {
            Serial.write("<AC>");
        }
        else
        {
            cpuTemp = buffer[0];

            cpuTempArr[cpuTempArrIter++] = cpuTemp;
            if (cpuTempArrIter >= tempArrSize)
            {
                cpuTempArrIter = 0;
            }
            //LCDController::print(14, 0, 'c');
            //LCDController::print(15, 0, cpuTemp);

            gpuTemp = buffer[1];

            gpuTempArr[gpuTempArrIter++] = gpuTemp;
            if (gpuTempArrIter >= tempArrSize)
            {
                gpuTempArrIter = 0;
            }
            //LCDController::print(14, 1, 'g');
            //LCDController::print(15, 1, gpuTemp);
        }
        newDataRecieved = false;
    }
} // namespace dh
