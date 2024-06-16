#ifndef RCLOCK_H
#define RCLOCK_H

#include <Arduino.h>
#include <Wire.h>
#include "utility/BM8563.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

class RClock {
public:
    RClock();
    void begin();
    void getTime(rtc_time_t &time);
    void getDate(rtc_date_t &date);
    void setTime(const rtc_time_t &time);
    void setDate(const rtc_date_t &date);
    String getFormattedTime();
    String getFormattedDate();

private:
    BM8563 rtc;
    SemaphoreHandle_t mutex;
    void setInitialTime(const rtc_time_t &time, const rtc_date_t &date);
};

#endif 