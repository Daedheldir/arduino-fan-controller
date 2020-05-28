#include "include/ManagingInterface.h"

dh::ManagingInterface interface;

void setup()
{
  Serial.begin(9600);

  interface.setupManager();
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), fan1_rpm, RISING);
}

void loop()
{
  // put your main code here, to run repeatedly:
  interface.updateManager();
}

void fan1_rpm()
{
  interface.fan1_interrupt();
  //Serial.println("Interrupt");
}

void fan2_rpm()
{
  interface.fan2_interrupt();
}
