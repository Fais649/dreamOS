#include "Hardware.h"
#include "Software.h"

void setup()
{
  initHardware();
  initUtils();
  initStart();
  initManagers();
}

void initHardware()
{
  power.begin();
  Serial.println("Power initialized!");
  delay(200);
  ports.begin();
  Serial.println("Ports initialized!");
  delay(200);
  display.begin();
  Serial.println("Display initialized!");
  delay(200);
  touchPanel.begin(21, 22, 36);
  Serial.println("TouchPanel initialized!");
  delay(200);
  battery.begin();
  Serial.println("Battery intialized: " + String(battery.getBatteryPercentage()));
  rclock.begin();
  Serial.println("Clock initialized!");
  // sdCard.begin();
}

void initStart()
{
  todoTask.start();
  delay(200);
  Serial.println("Start App initialized!");
}

void initUtils()
{
  touchPanelTask.start();
  Serial.println("TouchPanel Task initialized!");
  delay(200);
  keyboardTask.start();
  delay(200);
  Serial.println("Keyboard Task initialized!");
}

void initManagers()
{
  appSwitcherTask.start();
   delay(200);
  powerTask.start();
}

void loop() {}