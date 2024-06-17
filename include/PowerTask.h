#ifndef POWERTASK_H
#define POWERTASK_H

#include "TaskClass.h"
#include "Tasks.h"
#include "AppTaskClass.h"
#include "AppSwitcherTask.h"

class PowerTask : public TaskClass
{
public:
    PowerTask();

protected:
    void taskFunction() override;
};

extern PowerTask powerTask;

#endif
