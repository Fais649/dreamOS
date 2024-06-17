#ifndef APPSWITCHERTASK_H
#define APPSWITCHERTASK_H

#include "Tasks.h"
#include "AppTaskClass.h"

class AppSwitcherTask : public TaskClass
{
public:
    AppSwitcherTask();

protected:
    void taskFunction() override;

private:
    void setCurrentApp(AppTaskClass *appTask)
    {
        Serial.println("Switching to: " + String(appTask->getTaskName()));
        currentApp = appTask;
    };

    AppTaskClass *currentApp = nullptr;
};

extern AppSwitcherTask appSwitcherTask;

#endif
