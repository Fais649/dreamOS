#ifndef TODOTASK_H
#define TODOTASK_H

#include "AppTaskClass.h"

class TodoTask : public AppTaskClass
{
public:
    TodoTask();
protected:
    void taskFunction() override;
    void updateDisplay() override;
};

#endif
