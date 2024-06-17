#include "TodoTask.h"
#include "TaskList.h"
#include "Software.h"

#define TODO_LIST_MAX_COLS 34
#define TODO_LIST_MAX_ROWS 10

#define TODO_LIST_TITLE_SIZE 6
#define TODO_LIST_DATE_SIZE 3
#define TODO_LIST_FONT_SIZE 4
#define TODO_LIST_FONT_NUMBER 4

#define TODO_LIST_WIDTH 790
#define TODO_LIST_HEIGHT 320

#define TODO_LIST_TEXT_WIDTH 23
#define TODO_LIST_TEXT_HEIGHT 30

#define TODO_LIST_X 112
#define TODO_LIST_Y 150

TaskList todoTaskList(
    TODO_LIST_X,
    TODO_LIST_Y,
    TODO_LIST_MAX_ROWS,
    TODO_LIST_MAX_COLS,
    TODO_LIST_TEXT_WIDTH,
    TODO_LIST_TEXT_HEIGHT,
    TODO_LIST_FONT_SIZE,
    TODO_LIST_FONT_NUMBER,
    TODO_LIST_WIDTH,
    TODO_LIST_HEIGHT,
    ListType::TYPE_FREE);

TodoTask::TodoTask()
    : AppTaskClass(TODO_TASK, 1, 10000, 1) {}

void TodoTask::setCanvas()
{
    display.getCanvas().deleteCanvas();
    display.createCanvas(TODO_LIST_TEXT_WIDTH * TODO_LIST_MAX_COLS, TODO_LIST_TEXT_HEIGHT);
    display.clear();
    display.setTextSize(TODO_LIST_FONT_SIZE);
}

void TodoTask::taskFunction()
{
    while (true)
    {
        if (textInputBuffer.isUpdate())
        {
            String buffer = textInputBuffer.getBuffer();
            todoTaskList.handleTextInputBuffer(buffer.c_str());
            // updateDisplay();
        }

        Serial.println("Todo alive!");
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

void TodoTask::updateDisplay()
{
    // display.clear();
    // display.drawString(todoTaskList.getActiveRow(), 0, 0);
    // display.drawList(0, 0, TODO_LIST_TEXT_WIDTH, TODO_LIST_TEXT_HEIGHT, todoTaskList.getList(), TODO_LIST_MAX_ROWS, TODO_LIST_MAX_COLS);
    // display.pushCanvas(TODO_LIST_PADDING_X, TODO_LIST_PADDING_Y + (todoTaskList.getActiveRowNum() * TODO_LIST_TEXT_HEIGHT), UPDATE_MODE_DU4);
}