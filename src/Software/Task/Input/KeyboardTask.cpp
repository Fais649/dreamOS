#include "KeyboardTask.h"

KeyboardTask::KeyboardTask()
    : TaskClass("KeyboardTask", 20, 5000, 0) {}

void KeyboardTask::taskFunction()
{
    while (true)
    {
        keyboard.scan();
        if (keyboard.isKeyPressed())
        {
            textInputBuffer.addChar(keyboard.getChar());
        }
        vTaskDelay(20 / portTICK_PERIOD_MS);
    }
}