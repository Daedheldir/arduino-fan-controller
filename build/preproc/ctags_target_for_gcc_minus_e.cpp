# 1 "d:\\Work\\CNC\\Projects\\Laptop Stand\\Programs\\Sketch\\ArduinoFanController\\Sketch\\Sketch.ino"
# 2 "d:\\Work\\CNC\\Projects\\Laptop Stand\\Programs\\Sketch\\ArduinoFanController\\Sketch\\Sketch.ino" 2

dh::ManagingInterface interface;

void setup()
{
  Serial.begin(9600);

  interface.setupManager();
  // put your setup code here, to run once:
  pinMode(2, 0x2);
  attachInterrupt(((2) == 2 ? 0 : ((2) == 3 ? 1 : -1)), fan1_rpm, 3);
  pinMode(3, 0x2);
  attachInterrupt(((3) == 2 ? 0 : ((3) == 3 ? 1 : -1)), fan2_rpm, 3);
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
