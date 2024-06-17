#include "TouchPanelTask.h"

TouchPanelTask::TouchPanelTask()
    : TaskClass("TouchPanelTask", 20, 5000, 0) {}

void TouchPanelTask::taskFunction()
{
    while (true)
    {
        touchPanel.update();
        if (!touchPanel.isFingerUp())
        {
            Serial.println(touchPanel.readFingerX(0));
            Serial.println(touchPanel.readFingerY(0));
        }
        vTaskDelay(20 / portTICK_PERIOD_MS);
    }
}