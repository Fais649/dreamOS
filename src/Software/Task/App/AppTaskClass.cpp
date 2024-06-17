#include "AppTaskClass.h"

AppTaskClass::AppTaskClass(const char *name, UBaseType_t priority, uint32_t stackSize, uint8_t taskCore)
    : TaskClass(name, priority, stackSize, taskCore) {}

