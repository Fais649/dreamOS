#include "TaskList.h"

TaskList::TaskList(
    int listPosX,
    int listPosY,
    int maxRows,
    int maxCols,
    int textWidth,
    int textHeight,
    int fontSize,
    int fontNumber,
    ListType type) : _listPosX(listPosX),
                     _listPosY(listPosY),
                     _maxRows(maxRows),
                     _maxCols(maxCols),
                     _textWidth(textWidth),
                     _textHeight(textHeight),
                     _fontSize(fontSize),
                     _fontNumber(fontNumber),
                     _type(type)
{
    // display.getCanvas().setTextFont(_fontNumber);
    display.getCanvas().setTextSize(_fontSize);
    _charMatrix = new char *[_maxRows];
    for (int i = 0; i < _maxRows; i++)
    {
        _charMatrix[i] = new char[_maxCols + 1];
        memset(_charMatrix[i], 0, _maxCols + 1);
    }
    _cursorChar = _charMatrix[_cursorPosY][_cursorPosX];
}

TaskList::~TaskList()
{
    for (int i = 0; i < _maxRows; i++)
    {
        delete[] _charMatrix[i];
    }
    delete[] _charMatrix;
}

char *TaskList::getListRow(int posY)
{
    return _charMatrix[posY];
}

String TaskList::getActiveRow()
{
    return String(_charMatrix[_cursorPosY]);
}

int TaskList::getActiveRowNum()
{
    return _cursorPosY;
}

int TaskList::getActiveColNum()
{
    return _cursorPosX;
}

void TaskList::handleInput(char input)
{
    _input = input;
    if (isNewChar())
    {
        handleNewChar();
    }
    else if (isNewBackspace())
    {
        handleBackspace();
    }
    else if (isNewEnter())
    {
        handleEnter();
    }
    else if (isNewEsc())
    {
        handleEsc();
    }
    else if (isNewTab())
    {
        handleTab();
    }
    else if (isNewUp())
    {
        handleUp();
    }
    else if (isNewDown())
    {
        handleDown();
    }
    vTaskDelay(1 / portTICK_PERIOD_MS);
}

void TaskList::draw()
{
    // display.clear();
    // display.drawString(_cursorChar)
}

void TaskList::handleNewChar()
{
    if (_cursorPosX < _maxCols - 2)
    {
        updateCursorChar();
        updateCharAtCurrPos();
        cursorRight();
        cursorBlinkChar();
        addNullTerminator(1);
    }
}

void TaskList::handleBackspace()
{
    if (_cursorPosX > 0)
    {
        display.getCanvas().deleteCanvas();
        display.createCanvas(_textWidth, _textHeight);
        display.clear();
        display.pushCanvas(calcPosX(), calcPosY(), UPDATE_MODE_DU4);
        
        cursorLeft();
        cursorBlinkChar();
        addNullTerminator(1);
    }
}

void TaskList::handleEnter()
{
    if (_cursorPosY < _maxRows)
    {
        _currentMaxRow++;
        display.getCanvas().deleteCanvas();
        display.createCanvas(_textWidth, _textHeight);
        display.clear();
        display.pushCanvas(calcPosX(), calcPosY(), UPDATE_MODE_DU4);

        addNullTerminator(0);
        cursorDown();
        cursorResetX();

        display.getCanvas().deleteCanvas();
        display.createCanvas((_maxCols - 1) * _textWidth, _textHeight);
        display.clear();
        display.pushCanvas(_listPosX, calcPosY(), UPDATE_MODE_DU4);
        
        cursorBlinkChar();
        addNullTerminator(1);
    }
}

void TaskList::handleTab()
{
    // TODO: Tab Logic
}

void TaskList::handleEsc()
{
    if (_cursorPosX > 0)
    {
        display.getCanvas().deleteCanvas();
        display.createCanvas((_maxCols - 1) * _textWidth, _textHeight);
        display.clear();
        display.pushCanvas(_listPosX, calcPosY(), UPDATE_MODE_DU4);
        cursorResetX();
        cursorBlinkChar();
        addNullTerminator(1);
    }
}

void TaskList::handleUp()
{
    if (_cursorPosY > 0)
    {
        addNullTerminator(0);
        cursorUp();
        cursorRightMax();
        cursorBlinkChar();
        addNullTerminator(1);
    }
}

void TaskList::handleDown()
{
    if (_cursorPosY < _maxRows - 1)
    {
        addNullTerminator(0);
        cursorDown();
        cursorRightMax();
        cursorBlinkChar();
        addNullTerminator(1);
    }
}

void TaskList::handleReset()
{
    display.getCanvas().deleteCanvas();
    display.createCanvas(_maxCols * _textWidth, _maxRows * _textHeight);
    display.clear();
    display.pushCanvas(_listPosX, _listPosY, UPDATE_MODE_DU4);
    memset(_charMatrix, 0, sizeof(_charMatrix));
    cursorResetX();
    cursorResetY();
    cursorBlinkChar();
    addNullTerminator(1);
}

void TaskList::updateCursorChar()
{
    _cursorChar = _input;
}

void TaskList::cursorBlinkChar()
{
    _charMatrix[_cursorPosY][_cursorPosX] = _cursorBlinkChar;
    display.getCanvas().deleteCanvas();
    display.createCanvas(_textWidth, _textHeight);
    display.clear();
    display.drawChar(_cursorBlinkChar, 0, 0);
    display.pushCanvas(calcPosX(), calcPosY(), UPDATE_MODE_DU4);
}

void TaskList::updateCharAtCurrPos()
{
    _charMatrix[_cursorPosY][_cursorPosX] = _cursorChar;
    display.getCanvas().deleteCanvas();
    display.createCanvas(_textWidth, _textHeight);
    display.clear();
    display.drawChar(_cursorChar, 0, 0);
    display.pushCanvas(calcPosX(), calcPosY(), UPDATE_MODE_DU4);
}

int TaskList::calcPosX()
{
    return _listPosX + (_textWidth * _cursorPosX);
}

int TaskList::calcPosY()
{
    return _listPosY + (_textHeight * _cursorPosY);
}

void TaskList::addNullTerminator(int xOffset)
{
    _charMatrix[_cursorPosY][_cursorPosX + xOffset] = '\0';
}

void TaskList::cursorRight()
{
    if (_cursorPosX < _maxCols)
    {
        _cursorPosX++;
    }
}

void TaskList::cursorLeft()
{
    if (_cursorPosX > 0)
    {
        _cursorPosX--;
    }
}

void TaskList::cursorDown()
{
    if (_cursorPosY < _maxRows - 1)
    {
        display.getCanvas().deleteCanvas();
        display.createCanvas(_textWidth, _textHeight);
        display.clear();
        display.pushCanvas(calcPosX(), calcPosY(), UPDATE_MODE_DU4);
        _cursorPosY++;
    }
}

void TaskList::cursorUp()
{
    if (_cursorPosY > 0)
    {
        display.getCanvas().deleteCanvas();
        display.createCanvas(_textWidth, _textHeight);
        display.clear();
        display.pushCanvas(calcPosX(), calcPosY(), UPDATE_MODE_DU4);
        _cursorPosY--;
    }
}

void TaskList::cursorRightMax()
{
    _cursorPosX = strlen(_charMatrix[_cursorPosY]);
}

void TaskList::cursorResetX()
{
    _cursorPosX = 0;
}

void TaskList::cursorResetY()
{
    _cursorPosY = 0;
}

bool TaskList::isNewChar()
{
    return _input >= 32 && _input <= 126 && _cursorPosX < _maxCols;
}

bool TaskList::isNewBackspace()
{
    return _input == 8 && _cursorPosX > 0;
}

bool TaskList::isNewEnter()
{
    return _input == 13 && _cursorPosY < _maxRows;
}

bool TaskList::isNewEsc()
{
    return _input == 27 && _cursorPosX > 0;
}

bool TaskList::isNewUp()
{
    return _input == 181 && _cursorPosX < _maxCols;
}

bool TaskList::isNewDown()
{
    return _input == 182 && _cursorPosX < _maxCols;
}

bool TaskList::isNewTab()
{
    return _input == 9 && _cursorPosX < _maxCols;
}

bool TaskList::isNewLeft()
{
    return _input == 180 && _cursorPosX < _maxCols;
}

bool TaskList::isNewRight()
{
    return _input == 183 && _cursorPosX < _maxCols;
}

void TaskList::handleTextInputBuffer(const char buffer[BUFFER_SIZE])
{
    Serial.println("HandleTextBuffer");
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        if (buffer[i] == '\0')
        {
            break;
        }
        handleInput(buffer[i]);
    }
}

bool TaskList::isBufferChange()
{
    return _bufferChange;
}