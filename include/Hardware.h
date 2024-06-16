#ifndef HARDWARE_H
#define HARDWARE_H 

#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "Power.h"
#include "Ports.h"
#include "Display.h"
#include "TouchPanel.h"
#include "SDCard.h"
#include "Battery.h"
#include "RClock.h"
#include "Buttons.h"
#include "CardKb.h"
#include <esp_sleep.h> 
#include "TextInputBuffer.h"

extern Power power;
extern Display display;
extern Ports ports;
extern Battery battery;
extern RClock rclock;
extern TouchPanel touchPanel;
extern SDCard sdCard;
extern Buttons buttons;
extern CardKb keyboard;
extern TextInputBuffer textInputBuffer;

#endif