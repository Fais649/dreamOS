#ifndef BUTTONS_H
#define BUTTONS_H

#include "Buttons.h"
#include "utility/Button.h"
#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>
#include "Globals.h"

class Buttons {
public:
    Buttons();
    void update();
    Button BtnL;
    Button BtnR;
    Button BtnP;

private:
    SemaphoreHandle_t mutex;
};

#endif
