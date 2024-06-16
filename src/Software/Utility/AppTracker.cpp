#include "AppTracker.h"

String currentApp;

String getCurrentApp() {
    return currentApp;
}

void setCurrentApp(const String &app) {
    currentApp = app;
}