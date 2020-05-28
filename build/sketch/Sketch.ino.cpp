#include <Arduino.h>
#line 1 "d:\\Work\\CNC\\Projects\\Laptop Stand\\Programs\\Sketch\\ArduinoFanController\\Sketch\\Sketch.ino"
#include "include/ManagingInterface.h"

dh::ManagingInterface interface;

#line 5 "d:\\Work\\CNC\\Projects\\Laptop Stand\\Programs\\Sketch\\ArduinoFanController\\Sketch\\Sketch.ino"
void setup();
#line 15 "d:\\Work\\CNC\\Projects\\Laptop Stand\\Programs\\Sketch\\ArduinoFanController\\Sketch\\Sketch.ino"
void loop();
#line 21 "d:\\Work\\CNC\\Projects\\Laptop Stand\\Programs\\Sketch\\ArduinoFanController\\Sketch\\Sketch.ino"
void fan1_rpm();
#line 27 "d:\\Work\\CNC\\Projects\\Laptop Stand\\Programs\\Sketch\\ArduinoFanController\\Sketch\\Sketch.ino"
void fan2_rpm();
#line 5 "d:\\Work\\CNC\\Projects\\Laptop Stand\\Programs\\Sketch\\ArduinoFanController\\Sketch\\Sketch.ino"
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

