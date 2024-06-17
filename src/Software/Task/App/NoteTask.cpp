#include "NoteTask.h"
#include "TaskList.h"
#include "Software.h"

#define NOTE_LIST_MAX_COLS 34
#define NOTE_LIST_MAX_ROWS 10

#define NOTE_LIST_TITLE_SIZE 6
#define NOTE_LIST_DATE_SIZE 3
#define NOTE_LIST_TEXT_SIZE 4
#define NOTE_LIST_FONT_NUMBER 4

#define NOTE_LIST_WIDTH 790
#define NOTE_LIST_HEIGHT 320

#define NOTE_LIST_TEXT_WIDTH 23
#define NOTE_LIST_TEXT_HEIGHT 30

#define NOTE_LIST_PADDING_X 112
#define NOTE_LIST_PADDING_Y 150

TaskList noteTaskList(
    NOTE_LIST_MAX_ROWS,
    NOTE_LIST_MAX_COLS,
    NOTE_LIST_TEXT_WIDTH,
    NOTE_LIST_TEXT_HEIGHT,
    NOTE_LIST_FONT_SIZE,
    NOTE_LIST_FONT_NUMBER,
    NOTE_LIST_WIDTH,
    NOTE_LIST_HEIGHT,
    ListType::TYPE_FREE);

NoteTask::NoteTask()
    : AppTaskClass(NOTE_TASK, 1, 10000, 1) {}

void NoteTask::setCanvas()
{
    display.getCanvas().deleteCanvas();
    display.createCanvas(TASK_LIST_WIDTH, TASK_LIST_HEIGHT);
    display.clear();
    display.setTextSize(TASK_LIST_TEXT_SIZE);
}

void NoteTask::taskFunction()
{
    display.createCanvas(TASK_LIST_WIDTH, TASK_LIST_HEIGHT);
    while (true)
    {
        if (textInputBuffer.isUpdate())
        {
            String buffer = textInputBuffer.getBuffer();
            Serial.println(buffer.c_str());
            noteTaskList.handleTextInputBuffer(buffer.c_str());
        }

        Serial.println("Note alive!");
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

void NoteTask::updateDisplay()
{
}
