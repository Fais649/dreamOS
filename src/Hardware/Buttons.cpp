#include "Buttons.h"

Buttons::Buttons()
    : BtnL(M5EPD_KEY_LEFT_PIN, true, 30),
      BtnR(M5EPD_KEY_RIGHT_PIN, true, 30),
      BtnP(M5EPD_KEY_PUSH_PIN, true, 50)
{
    mutex = xSemaphoreCreateMutex();
}

void Buttons::update()
{
    xSemaphoreTake(mutex, portMAX_DELAY);

    BtnL.read();
    BtnR.read();
    BtnP.read();

    xSemaphoreGive(mutex);
}
