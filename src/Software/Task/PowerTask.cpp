#include "PowerTask.h"

PowerTask::PowerTask()
    : TaskClass("PowerTask", 5, 5000, 1) {}

void PowerTask::taskFunction()
{
    while (1)
    {
        buttons.update();
        if (buttons.BtnP.isPressed())
        {
            vTaskDelay(10 / portTICK_PERIOD_MS);
            if (buttons.BtnP.isPressed())
            {
                display.createCanvas(50, 20);
                display.drawString("...", 0, 0);
                display.pushCanvas(800, 0, UPDATE_MODE_A2);
                display.getCanvas().deleteCanvas();

                // keyboardTask.stop();
                // vTaskDelay(50 / portTICK_PERIOD_MS);
                // touchPanelTask.stop();
                // vTaskDelay(50 / portTICK_PERIOD_MS);
                // appSwitcherTask.stop();
                // vTaskDelay(50 / portTICK_PERIOD_MS);
                // appTask->getCurrentApp()->stop();
                // vTaskDelay(50 / portTICK_PERIOD_MS);

                vTaskSuspendAll();
                vTaskDelay(100 / portTICK_PERIOD_MS);
                esp_sleep_enable_ext0_wakeup(GPIO_NUM_38, 0);
                esp_light_sleep_start(); // Enter light sleep
                vTaskDelay(100 / portTICK_PERIOD_MS);
                xTaskResumeAll();

                // vTaskDelay(50 / portTICK_PERIOD_MS);
                // keyboardTask.start();
                // vTaskDelay(50 / portTICK_PERIOD_MS);
                // touchPanelTask.start();
                // vTaskDelay(50 / portTICK_PERIOD_MS);
                // appSwitcherTask.start();
                // vTaskDelay(50 / portTICK_PERIOD_MS);
                // appTask->getCurrentApp()->stop();
            }
        }
        vTaskDelay(200 / portTICK_PERIOD_MS);
    }
}

PowerTask powerTask;