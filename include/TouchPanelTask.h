#ifndef TOUCHPANELTASK_H
#define TOUCHPANELTASK_H

#include "TaskClass.h"

class TouchPanelTask : public TaskClass {
public:
    TouchPanelTask();
protected:
    void taskFunction() override;
};

#endif
