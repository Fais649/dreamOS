#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include "M5EPD_Driver.h"
#include "M5EPD_Canvas.h"
#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>
#include "Globals.h"
#include "DisplayConstants.h"
#include "TaskListConsts.h"

class Display
{
public:
    Display();
    void begin();
    void createCanvas(int32_t width, int32_t height);
    void drawPixel(int32_t x, int32_t y, uint32_t color);
    void fillRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color);
    void drawRoundRect(int32_t x, int32_t y, int32_t w, int32_t h, int32_t r, uint32_t color);
    void pushCanvas(int32_t x, int32_t y, m5epd_update_mode_t mode);
    void clear();
    void drawLine(int32_t x0, int32_t y0, int32_t x1, int32_t y1, uint8_t thickness, uint8_t color);
    void drawFastVLine(int32_t x, int32_t y, int32_t h, uint8_t thickness, uint8_t color);
    void drawFastHLine(int32_t x, int32_t y, int32_t w, uint8_t thickness, uint8_t color);
    void drawRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color);
    void fillRoundRect(int32_t x, int32_t y, int32_t w, int32_t h, int32_t r, uint32_t color);
    void drawCircle(int32_t x, int32_t y, int32_t r, uint32_t color);
    void fillCircle(int32_t x, int32_t y, int32_t r, uint32_t color);
    void fillCanvas(uint32_t color);
    void reverseColor();
    void setTextFont(uint8_t font);
    void setTextSize(uint32_t size);
    void setTextColor(uint8_t color);
    int16_t drawChar(int input, int32_t poX, int32_t poY);
    int16_t drawString(const String &string, int32_t poX, int32_t poY);
    void drawList(int32_t startX, int32_t startY, int32_t charWidth, int32_t charHeight, const char list[][TASK_LIST_MAX_COLS], int32_t rows, int32_t cols);
    void drawBitmap(int32_t x, int32_t y, const uint8_t *bitmap, int32_t w, int32_t h);
    M5EPD_Canvas(&getCanvas()) { return canvas; };

private:
    M5EPD_Canvas canvas;
    M5EPD_Driver epd_driver;
    SemaphoreHandle_t mutex;
};

#endif