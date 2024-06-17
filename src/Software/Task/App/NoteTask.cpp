#include "NoteTask.h"
#include "TaskList.h"
#include "Software.h"

#define NOTE_LIST_MAX_COLS 34
#define NOTE_LIST_MAX_ROWS 10

#define NOTE_LIST_FONT_SIZE 2
#define NOTE_LIST_FONT_NUMBER 4

#define NOTE_LIST_WIDTH 790
#define NOTE_LIST_HEIGHT 320

#define NOTE_LIST_TEXT_WIDTH 24
#define NOTE_LIST_TEXT_HEIGHT 32

#define NOTE_LIST_X 95
#define NOTE_LIST_Y 160

TaskList *noteTaskList = nullptr;

NoteTask::NoteTask()
    : AppTaskClass(NOTE_TASK, 1, 10000, 1) {}

void NoteTask::start()
{
    AppTaskClass::start();
    noteTaskList = new TaskList(
        NOTE_LIST_X,
        NOTE_LIST_Y,
        NOTE_LIST_MAX_ROWS,
        NOTE_LIST_MAX_COLS,
        NOTE_LIST_TEXT_WIDTH,
        NOTE_LIST_TEXT_HEIGHT,
        NOTE_LIST_FONT_SIZE,
        NOTE_LIST_FONT_NUMBER,
        ListType::TYPE_FREE);
}

void NoteTask::stop() {
    delete noteTaskList;
    AppTaskClass::stop();
}

void NoteTask::taskFunction()
{
    while (true)
    {
        if (textInputBuffer.isUpdate())
        {
            String buffer = textInputBuffer.getBuffer();
            Serial.println(buffer.c_str());
            noteTaskList->handleTextInputBuffer(buffer.c_str());
        }

        Serial.println("Note alive!");
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

void NoteTask::updateDisplay()
{
}
