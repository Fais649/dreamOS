#ifndef TASKCLASS_H
#define TASKCLASS_H

#include "Hardware.h"
#include "Globals.h"

class TaskClass
{
public:
    TaskClass(const char *name, UBaseType_t priority, uint32_t stackSize, uint8_t core);
    ~TaskClass();

    virtual void start()
    {
        xTaskCreatePinnedToCore(taskFunctionWrapper, taskName, taskStackSize, this, taskPriority, &taskHandle, taskCore);
    };

    virtual void stop()
    {
        if (taskHandle != nullptr)
        {
            vTaskDelete(taskHandle);
            taskHandle = nullptr;
        }
    };

    static void taskFunctionWrapper(void *parameter);
    TaskHandle_t getHandle() { return taskHandle; }
    const char (*getTaskName()){ return taskName; }
protected:
    virtual void taskFunction() = 0;
    const char *taskName;
    TaskHandle_t taskHandle;

private:
    UBaseType_t taskPriority;
    uint32_t taskStackSize;
    uint8_t taskCore;
};

#endif // TASKCLASS_H
