#include "AppSwitcherTask.h"

AppSwitcherTask::AppSwitcherTask()
    : TaskClass("AppSwitcherTask", 5, 5000, 1) {}

void AppSwitcherTask::taskFunction()
{
    while (1)
    {
        buttons.update();
        if (buttons.BtnL.isPressed())
        {
            vTaskDelay(10 / portTICK_PERIOD_MS);
            if (buttons.BtnL.isPressed())
            {
                if (noteTask.getHandle() != nullptr)
                {
                    noteTask.stop();
                    vTaskDelay(200 / portTICK_PERIOD_MS);
                    todoTask.start();
                }
                else if (todoTask.getHandle() != nullptr)
                {
                    todoTask.stop();
                    vTaskDelay(200 / portTICK_PERIOD_MS);
                    noteTask.start();
                }
            }
        }
        vTaskDelay(200 / portTICK_PERIOD_MS);
    }
}

AppSwitcherTask appSwitcherTask;
