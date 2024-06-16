
#ifndef NOTETASK_H
#define NOTETASK_H

#include "AppTaskClass.h"

class NoteTask : public AppTaskClass
{
public:
    NoteTask();

protected:
    void taskFunction() override;
    void updateDisplay() override;
};

#endif
