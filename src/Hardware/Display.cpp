#include "Display.h"

Display::Display() : canvas(&epd_driver)
{
    mutex = xSemaphoreCreateMutex();
}

void Display::begin()
{
    xSemaphoreTake(mutex, portMAX_DELAY);
    if (epd_driver.begin(M5EPD_SCK_PIN, M5EPD_MOSI_PIN, M5EPD_MISO_PIN, M5EPD_CS_PIN, M5EPD_BUSY_PIN) != M5EPD_OK)
    {
        Serial.println("EPD driver initialization failed!");
    }
    xSemaphoreGive(mutex);
}

void Display::createCanvas(int32_t width, int32_t height)
{
    xSemaphoreTake(mutex, portMAX_DELAY);
     canvas.createCanvas(width, height);
    xSemaphoreGive(mutex);
}

void Display::pushCanvas(int32_t x, int32_t y, m5epd_update_mode_t mode)
{
    xSemaphoreTake(mutex, portMAX_DELAY);
    canvas.pushCanvas(x, y, mode);
    xSemaphoreGive(mutex);
}

void Display::clear()
{
    xSemaphoreTake(mutex, portMAX_DELAY);
    canvas.clear();
    xSemaphoreGive(mutex);
}

void Display::reverseColor()
{
    xSemaphoreTake(mutex, portMAX_DELAY);
    canvas.ReverseColor();
    xSemaphoreGive(mutex);
}

void Display::setTextFont(uint8_t font)
{
    xSemaphoreTake(mutex, portMAX_DELAY);
    canvas.setTextFont(font);
    xSemaphoreGive(mutex);
}

void Display::setTextSize(uint32_t size)
{
    xSemaphoreTake(mutex, portMAX_DELAY);
    canvas.setTextSize(size);
    xSemaphoreGive(mutex);
}

void Display::setTextColor(uint8_t color)
{
    xSemaphoreTake(mutex, portMAX_DELAY);
    canvas.setTextColor(color);
    xSemaphoreGive(mutex);
}

void Display::drawPixel(int32_t x, int32_t y, uint32_t color)
{
    xSemaphoreTake(mutex, portMAX_DELAY);
    canvas.drawPixel(x, y, color);
    xSemaphoreGive(mutex);
}

void Display::drawLine(int32_t x0, int32_t y0, int32_t x1, int32_t y1, uint8_t thickness, uint8_t color)
{
    xSemaphoreTake(mutex, portMAX_DELAY);
    canvas.drawLine(x0, y0, x1, y1, thickness, color);
    xSemaphoreGive(mutex);
}

void Display::drawFastVLine(int32_t x, int32_t y, int32_t h, uint8_t thickness, uint8_t color)
{
    xSemaphoreTake(mutex, portMAX_DELAY);
    canvas.drawFastVLine(x, y, h, thickness, color);
    xSemaphoreGive(mutex);
}

void Display::drawFastHLine(int32_t x, int32_t y, int32_t w, uint8_t thickness, uint8_t color)
{
    xSemaphoreTake(mutex, portMAX_DELAY);
    canvas.drawFastHLine(x, y, w, thickness, color);
    xSemaphoreGive(mutex);
}

void Display::drawRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color)
{
    xSemaphoreTake(mutex, portMAX_DELAY);
    canvas.drawRect(x, y, w, h, color);
    xSemaphoreGive(mutex);
}

void Display::fillRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color)
{
    xSemaphoreTake(mutex, portMAX_DELAY);
    canvas.fillRect(x, y, w, h, color);
    xSemaphoreGive(mutex);
}

void Display::drawRoundRect(int32_t x, int32_t y, int32_t w, int32_t h, int32_t r, uint32_t color)
{
    xSemaphoreTake(mutex, portMAX_DELAY);
    canvas.drawRoundRect(x, y, w, h, r, color);
    xSemaphoreGive(mutex);
}

void Display::fillRoundRect(int32_t x, int32_t y, int32_t w, int32_t h, int32_t r, uint32_t color)
{
    xSemaphoreTake(mutex, portMAX_DELAY);
    canvas.fillRoundRect(x, y, w, h, r, color);
    xSemaphoreGive(mutex);
}

void Display::drawCircle(int32_t x, int32_t y, int32_t r, uint32_t color)
{
    xSemaphoreTake(mutex, portMAX_DELAY);
    canvas.drawCircle(x, y, r, color);
    xSemaphoreGive(mutex);
}

void Display::fillCircle(int32_t x, int32_t y, int32_t r, uint32_t color)
{
    xSemaphoreTake(mutex, portMAX_DELAY);
    canvas.fillCircle(x, y, r, color);
    xSemaphoreGive(mutex);
}

void Display::fillCanvas(uint32_t color)
{
    xSemaphoreTake(mutex, portMAX_DELAY);
    canvas.fillCanvas(color);
    xSemaphoreGive(mutex);
}

int16_t Display::drawString(const String &string, int32_t poX, int32_t poY)
{
    xSemaphoreTake(mutex, portMAX_DELAY);
    int16_t result = canvas.drawString(string, poX, poY);
    xSemaphoreGive(mutex);
    return result;
}

void Display::drawList(int32_t startX, int32_t startY, int32_t charWidth, int32_t charHeight, const char list[][TASK_LIST_MAX_COLS], int32_t rows, int32_t cols)
{
    xSemaphoreTake(mutex, portMAX_DELAY);

    for (int32_t y = 0; y < rows; y++)
    {
        for (int32_t x = 0; x < cols; x++)
        {
            if (list[y][x] == '\0')
            {
                break;
            }
            canvas.drawChar(list[y][x], startX + x * charWidth, startY + y * charHeight);
        }
    }

    xSemaphoreGive(mutex);
}

void Display::drawBitmap(int32_t x, int32_t y, const uint8_t *bitmap, int32_t w, int32_t h)
{
    xSemaphoreTake(mutex, portMAX_DELAY);
    for (int32_t j = 0; j < h; ++j)
    {
        for (int32_t i = 0; i < w; ++i)
        {
            uint8_t color = bitmap[j * w + i];
            if (color != 0) // Assuming 0 is the color for white (transparent)
            {
                canvas.drawPixel(x + i, y + j, color);
            }
        }
    }
    xSemaphoreGive(mutex);
}