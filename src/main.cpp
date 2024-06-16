#include "Hardware.h"
#include "Software.h"

void setup()
{
  power.begin();
  delay(200);
  ports.begin();
  delay(200);
  display.begin();
  delay(200);
  touchPanel.begin(21, 22, 36);
  delay(200);
  // sdCard.begin();

 battery.begin();
  Serial.println("Battery: " + String(battery.getBatteryPercentage()));

  rclock.begin();
  Serial.println("clock");

  touchPanelTask.start();
  Serial.println("TP");
  keyboardTask.start();
  Serial.println("Keyboard");
  todoTask.start();
  Serial.println("todo");
  // noteTask.start();
  Serial.println("note");
  appSwitcherTask.start();
  powerTask.start();
}

void loop() {}