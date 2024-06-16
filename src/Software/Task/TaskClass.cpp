#include "TaskClass.h"

TaskClass::TaskClass(const char *name, UBaseType_t priority, uint32_t stackSize, uint8_t core)
    : taskName(name), taskPriority(priority), taskStackSize(stackSize), taskHandle(nullptr), taskCore(core) {}

TaskClass::~TaskClass()
{
    if (taskHandle != nullptr)
    {
        vTaskDelete(taskHandle);
    }
}

void TaskClass::taskFunctionWrapper(void *parameter)
{
    TaskClass *task = static_cast<TaskClass *>(parameter);
    task->taskFunction();
}