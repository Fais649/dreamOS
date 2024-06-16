#ifndef POWERTASK_H
#define POWERTASK_H

#include "TaskClass.h"
#include "Tasks.h"

class PowerTask : public TaskClass
{
public:
    PowerTask();

protected:
    void taskFunction() override;

private:
    void drawLogo();
};

extern PowerTask powerTask;

#endif
