#ifndef TEXTINPUTBUFFER_H
#define TEXTINPUTBUFFER_H

#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

#define BUFFER_SIZE 10

class TextInputBuffer {
public:
    TextInputBuffer();
    void addChar(char c);
    String getBuffer();
    bool isUpdate();

private:
    char buffer[BUFFER_SIZE];
    int index;
    SemaphoreHandle_t mutex;
    bool _update;
};

#endif // TEXTINPUTBUFFER_H