#ifndef TASKLIST_H
#define TASKLIST_H

#include <Arduino.h>
#include <cstring>
#include "TaskListConsts.h"
#include "TextInputBuffer.h"
#include "Hardware.h"

enum class ListType
{
    TYPE_CHECKLIST = 0,
    TYPE_BULLETED,
    TYPE_NUMBERED,
    TYPE_FREE
};

class TaskList
{
public:
    TaskList(
        int listPosX,
        int listPosY,
        int maxRows,
        int maxCols,
        int textHeight,
        int textWidth,
        int fontSize,
        int fontNumber,
        int rowWidth,
        int rowHeight,
        ListType type = ListType::TYPE_FREE);

    ~TaskList();
    char *getListRow(int posY);
    String getActiveRow();
    int getActiveRowNum();
    int getActiveColNum();
    void handleReset();
    void handleTextInputBuffer(const char buffer[BUFFER_SIZE]);
    bool isBufferChange();
    void draw();

private:
    void handleInput(char input);
    ListType _type = ListType::TYPE_FREE;
    int _listPosX;
    int _listPosY;
    int _maxRows;
    int _maxCols;
    int _textHeight;
    int _textWidth;
    int _fontSize;
    int _fontNumber;
    int _rowWidth;
    int _rowHeight;

    bool _bufferChange = false;

    char **_charMatrix;
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

    int calcPosX();
    void calcPosY();
};

#endif