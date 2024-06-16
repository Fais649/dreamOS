#ifndef APPTRACKER_H
#define APPTRACKER_H

#include <Arduino.h>

extern String currentApp;

String getCurrentApp();

void setCurrentApp(const String &app);

#endif
