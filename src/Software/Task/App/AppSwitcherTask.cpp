#include "AppSwitcherTask.h"

AppSwitcherTask::AppSwitcherTask()
    : TaskClass("AppSwitcherTask", 5, 10000, 1) {}

void AppSwitcherTask::taskFunction()
{
    setCurrentApp(&todoTask);
    while (1)
    {
        buttons.update();
        if (buttons.BtnL.isPressed())
        {
            vTaskDelay(10 / portTICK_PERIOD_MS);
            if (buttons.BtnL.isPressed())
            {
                currentApp->drawLoading();
                if (noteTask.getHandle() != nullptr)
                {
                    Serial.println("STOPPING: " + String(currentApp->getTaskName()));
                    currentApp->stop();
                    vTaskDelay(200 / portTICK_PERIOD_MS);
                    Serial.println("Starting task: todo");
                    todoTask.start();
                    setCurrentApp(&todoTask);
                }
                else if (todoTask.getHandle() != nullptr)
                {
                    Serial.println("Stopping task: " + String(currentApp->getTaskName()));
                    currentApp->stop();
                    vTaskDelay(200 / portTICK_PERIOD_MS);
                    Serial.println("Starting task: note");
                    noteTask.start();
                    setCurrentApp(&noteTask);
                }
            }
        }

        Serial.println("AppSwitcher alive!");
        vTaskDelay(200 / portTICK_PERIOD_MS);
    }
}

AppSwitcherTask appSwitcherTask;
