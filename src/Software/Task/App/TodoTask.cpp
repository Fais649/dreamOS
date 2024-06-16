#include "TodoTask.h"
#include "TaskList.h"
#include "Software.h"

TodoTask::TodoTask()
    : AppTaskClass(TODO_TASK, 1, 10000, 1) {}

void TodoTask::taskFunction()
{
    display.createCanvas(TASK_LIST_WIDTH, TASK_LIST_HEIGHT);
    while (true)
    {
        if (textInputBuffer.isUpdate())
        {
            String buffer = textInputBuffer.getBuffer();
            Serial.println(buffer.c_str());
            taskList.handleTextInputBuffer(buffer.c_str());
            Serial.println(*taskList.getList());
            updateDisplay();
        }

        Serial.println("Todo alive");
        // Serial.println("Clock: " + rclock.getFormattedDate() + " " + rclock.getFormattedTime());

        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

// void TodoTask::initDisplay()
// {
//     display.getCanvas().deleteCanvas();
//     display.createCanvas(M5EPD_DISPLAY_WIDTH, M5EPD_DISPLAY_HEIGHT);
//     display.clear();
//     display.fillRoundRect(15, 55, 890, 470, 20, M5EPD_GREY);
//     display.fillRoundRect(30, 30, 900, 480, 30, M5EPD_BLACK);
//     display.fillRoundRect(40, 40, 880, 460, 20, M5EPD_WHITE);
//     display.fillCircle(90, 80, 15, M5EPD_BLACK);
//     display.fillCircle(130, 80, 15, M5EPD_BLACK);
//     display.fillCircle(90, 120, 15, M5EPD_BLACK);

//     rtc_date_t date;
//     rclock.getDate(date);
//     String dateStr = String(date.day) + "-" + String(date.mon) + "-" + String(date.year);

//     display.setTextSize(TASK_LIST_TITLE_SIZE);
//     display.drawString("todo;", 160, 60);

//     display.setTextSize(TASK_LIST_DATE_SIZE);
//     display.drawString("/" + dateStr, 122, 114);

//     display.setTextColor(M5EPD_BLACK);
//     display.pushCanvas(0, 0, UPDATE_MODE_GC16);
//     display.getCanvas().deleteCanvas();
//     display.createCanvas(TASK_LIST_WIDTH, TASK_LIST_HEIGHT);
// }

void TodoTask::updateDisplay()
{
    // Create the canvas with the correct dimensions
    display.clear();
    display.setTextSize(TASK_LIST_TEXT_SIZE);
    display.drawList(0, 0, TASK_LIST_TEXT_WIDTH, TASK_LIST_TEXT_HEIGHT, taskList.getList(), TASK_LIST_MAX_ROWS, TASK_LIST_MAX_COLS);
    display.pushCanvas(TASK_LIST_PADDING_X, TASK_LIST_PADDING_Y, UPDATE_MODE_DU4);
}