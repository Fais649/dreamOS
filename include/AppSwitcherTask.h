#ifndef APPSWITCHERTASK_H
#define APPSWITCHERTASK_H

#include "Tasks.h"

class AppSwitcherTask : public TaskClass
{
public:
    AppSwitcherTask();

protected:
    void taskFunction() override;
};

extern AppSwitcherTask appSwitcherTask;

#endif
