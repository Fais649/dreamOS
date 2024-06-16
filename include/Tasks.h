#ifndef TASKS_H
#define TASKS_H

#include "PowerTask.h" 
#include "AppSwitcherTask.h" 

#include "KeyboardTask.h" 
#include "TouchPanelTask.h" 

#include "TodoTask.h" 
#include "NoteTask.h" 


extern KeyboardTask keyboardTask;
extern TouchPanelTask touchPanelTask;

#define TODO_TASK "todo"
#define NOTE_TASK "note"
extern TodoTask todoTask;
extern NoteTask noteTask;

#endif