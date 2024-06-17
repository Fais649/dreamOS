#include "Hardware.h"
#include "Software.h"

void initHardware();
void initUtils();
void initStart();
void initManagers();

void setup()
{
  initHardware();
  initUtils();
  initStart();
  initManagers();
}

void loop() {}

void initHardware()
{
  power.begin();
  Serial.println("Power initialized!");
  delay(50);
  ports.begin();
  Serial.println("Ports initialized!");
  delay(50);
  display.begin();
  Serial.println("Display initialized!");
  delay(50);
  touchPanel.begin(21, 22, 36);
  Serial.println("TouchPanel initialized!");
  delay(50);
  battery.begin();
  Serial.println("Battery intialized: " + String(battery.getBatteryPercentage()));
  rclock.begin();
  Serial.println("Clock initialized!");
  // sdCard.begin();
}

void initStart()
{
  todoTask.start();
  delay(50);
  Serial.println("Start App initialized!");
}

void initUtils()
{
  touchPanelTask.start();
  Serial.println("TouchPanel Task initialized!");
  delay(50);
  keyboardTask.start();
  delay(50);
  Serial.println("Keyboard Task initialized!");
}

void initManagers()
{
  appSwitcherTask.start();
   delay(50);
  powerTask.start();
}