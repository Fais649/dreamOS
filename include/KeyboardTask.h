#ifndef KEYBOARDTASK_H
#define KEYBOARDTASK_H

#include "TaskClass.h"
#include "TextInputBuffer.h"

class KeyboardTask : public TaskClass {
public:
    KeyboardTask();
protected:
    void taskFunction() override;
};

#endif
