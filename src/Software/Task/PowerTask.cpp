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
                display.drawString("....", 0, 0);
                display.pushCanvas(800, 40, UPDATE_MODE_A2);
                display.getCanvas().deleteCanvas();

                keyboardTask.stop();
                vTaskDelay(50 / portTICK_PERIOD_MS);
                touchPanelTask.stop();
                vTaskDelay(50 / portTICK_PERIOD_MS);
                appSwitcherTask.stop();
                vTaskDelay(50 / portTICK_PERIOD_MS);
                todoTask.stop();
                vTaskDelay(50 / portTICK_PERIOD_MS);
                noteTask.stop();
                vTaskDelay(50 / portTICK_PERIOD_MS);
                
                esp_sleep_enable_ext0_wakeup(GPIO_NUM_38, 0);
                esp_light_sleep_start(); // Enter light sleep
                
                vTaskDelay(50 / portTICK_PERIOD_MS);
                keyboardTask.start();
                vTaskDelay(50 / portTICK_PERIOD_MS);
                touchPanelTask.start();
                vTaskDelay(50 / portTICK_PERIOD_MS);
                appSwitcherTask.start();
                vTaskDelay(50 / portTICK_PERIOD_MS);
                todoTask.start();
            }
        }
        vTaskDelay(50 / portTICK_PERIOD_MS);
    }
}

void PowerTask::drawLogo()
{
    display.fillCircle(DISPLAY_LOGO_GAP, DISPLAY_LOGO_GAP, DISPLAY_LOGO_RADIUS, M5EPD_GREY);
    display.fillCircle(DISPLAY_LOGO_GAP * 2, DISPLAY_LOGO_GAP, DISPLAY_LOGO_RADIUS, M5EPD_GREY);
    display.fillCircle(DISPLAY_LOGO_GAP, DISPLAY_LOGO_GAP * 2, DISPLAY_LOGO_RADIUS, M5EPD_GREY);
};

PowerTask powerTask;