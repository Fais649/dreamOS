#include "KeyboardTask.h"

KeyboardTask::KeyboardTask()
    : TaskClass("KeyboardTask", 10, 5000, 0) {}

void KeyboardTask::taskFunction()
{
    while (true)
    {
        keyboard.scan();
        if (keyboard.isKeyPressed())
        {
            textInputBuffer.addChar(keyboard.getChar());
        }
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}