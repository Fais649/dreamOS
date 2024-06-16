#include "TextInputBuffer.h"

TextInputBuffer::TextInputBuffer() : index(0) {
    mutex = xSemaphoreCreateMutex();
    memset(buffer, 0, BUFFER_SIZE);
    buffer[0] = '\0'; 
    _update = false;
}

void TextInputBuffer::addChar(char c) {
    xSemaphoreTake(mutex, portMAX_DELAY);
    _update = true;
    if (index < BUFFER_SIZE - 1) { 
        buffer[index] = c;
        index++; 
        buffer[index] = '\0'; 
    }
    xSemaphoreGive(mutex);
}

String TextInputBuffer::getBuffer() {
    xSemaphoreTake(mutex, portMAX_DELAY);
    String result(buffer);
    memset(buffer, 0, BUFFER_SIZE);
    buffer[0] = '\0'; 
    index = 0; 
    _update = false;
    xSemaphoreGive(mutex);
    return result;
}

bool TextInputBuffer::isUpdate() {
    return _update;
}