#pragma once
namespace dh
{
    class SerialController
    {
    public:
        SerialController() {}

        void init()
        {
        }
        void update()
        {
            if (Serial.available())
            {
                recieveWithDelimit();

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
                newData = false;
            }
        }

        int getCpuTemp()
        {
            if (tempArrSize == 1)
            {
                return cpuTemp;
            }
            int tempAverage = 0;
            for (int i = 0; i < tempArrSize; ++i)
            {
                tempAverage += cpuTempArr[i];
            }
            tempAverage /= tempArrSize;
            return tempAverage;
        }
        int getGpuTemp()
        {
            if (tempArrSize == 1)
            {
                return gpuTemp;
            }
            int tempAverage = 0;
            for (int i = 0; i < tempArrSize; ++i)
            {
                tempAverage += gpuTempArr[i];
            }
            tempAverage /= tempArrSize;
            return tempAverage;
        }

        void recieveWithDelimit()
        {
            bool recvInProgress = false;

            char startChar = '<';
            char endChar = '>';
            int bufferIter = 0;
            char recData;

            while (Serial.available() && newData == false)
            {
                recData = Serial.read();
                //LCDController::print(14, 0, bufferIter);

                //if started recieving
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
                        newData = true;
                    }
                }
                //if we arent recieving and the recData is the startChar
                else if (recData == startChar)
                {
                    //set recieving to true and bufferIter to start of the buffer
                    recvInProgress = true;

                    bufferIter = 0;
                }
                //delay(250);
            }
        }

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
