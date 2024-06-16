#include "NoteTask.h"
#include "TaskList.h"
#include "Software.h"

NoteTask::NoteTask()
    : AppTaskClass(NOTE_TASK, 1, 10000, 1) {}

void NoteTask::taskFunction()
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

        Serial.println("Note alive");
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void NoteTask::updateDisplay()
{
    display.clear();
    display.setTextSize(TASK_LIST_TEXT_SIZE);
    display.drawList(0, 0, TASK_LIST_TEXT_WIDTH, TASK_LIST_TEXT_HEIGHT, taskList.getList(), TASK_LIST_MAX_ROWS, TASK_LIST_MAX_COLS);
    display.pushCanvas(TASK_LIST_PADDING_X, TASK_LIST_PADDING_Y, UPDATE_MODE_DU4);
}
