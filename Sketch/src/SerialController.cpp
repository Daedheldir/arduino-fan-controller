#include "../include/SerialController.h"

namespace dh
{
    SerialController::SerialController()
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
        //bool recvInProgress = false;
        //int bufferIter = 0;
        char recData;

        char startChar = '<';
        char endChar = '>';

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
