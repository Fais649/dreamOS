
#ifndef NOTETASK_H
#define NOTETASK_H

#include "AppTaskClass.h"

class NoteTask : public AppTaskClass
{
public:
    NoteTask();
    void start() override;
    void stop() override;

protected:
    void taskFunction() override;
    void updateDisplay() override;
};

#endif
