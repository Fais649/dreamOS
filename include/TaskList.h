#ifndef TASKLIST_H
#define TASKLIST_H

#include <Arduino.h>
#include <cstring>
#include "TaskListConsts.h"
#include "TextInputBuffer.h"
#include "Hardware.h"

class TaskList
{
public:
    TaskList();
    char *getListRow(int posY);
    char (&getList())[TASK_LIST_MAX_ROWS][TASK_LIST_MAX_COLS] { return _charMatrix; };
    void handleReset();
    void handleTextInputBuffer(const char buffer[BUFFER_SIZE]);
    bool isBufferChange();
    void draw();

private:
    void handleInput(char input);
    int _maxRows;
    int _maxCols;

    bool _bufferChange = false;

    char _charMatrix[TASK_LIST_MAX_ROWS][TASK_LIST_MAX_COLS];
    int _cursorPosY = 0;
    int _cursorPosX = 0;
    int _cursorBlinkChar = '_';
    int _cursorChar = _charMatrix[_cursorPosY][_cursorPosX];

    char _input;
    void cursorRight();
    void cursorLeft();
    void cursorUp();
    void cursorDown();
    void cursorResetX();
    void cursorResetY();
    void cursorRightMax();

    void updateCursorChar();
    void cursorBlinkChar();

    void updateCharAtCurrPos();
    void addNullTerminator(int xOffset);

    bool isNewChar();
    bool isNewBackspace();
    bool isNewEnter();
    bool isNewEsc();
    bool isNewTab();
    bool isNewUp();
    bool isNewDown();
    bool isNewLeft();
    bool isNewRight();

    void handleNewChar();
    void handleBackspace();
    void handleEnter();
    void handleEsc();
    void handleTab();
    void handleUp();
    void handleDown();
};

extern TaskList taskList;

#endif