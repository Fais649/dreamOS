#include "RClock.h"

RClock::RClock() : rtc()
{
    mutex = xSemaphoreCreateMutex();
}

void RClock::begin()
{
    rtc.writeReg(0x00, 0x00);
    rtc.writeReg(0x01, 0x00);
    rtc.writeReg(0x0D, 0x00);
    // rtc_time_t initialTime = {20, 05, 0};      // 18:12:00
    // rtc_date_t initialDate = {3, 6, 12, 2024}; // Monday, June 12, 2024
    // setInitialTime(initialTime, initialDate);
}

void RClock::getTime(rtc_time_t &time)
{
    rtc.getTime(&time);
}

void RClock::getDate(rtc_date_t &date)
{
    rtc.getDate(&date);
}

void RClock::setTime(const rtc_time_t &time)
{
    rtc.setTime(&time);
}

void RClock::setDate(const rtc_date_t &date)
{
    rtc.setDate(&date);
}

void RClock::setInitialTime(const rtc_time_t &time, const rtc_date_t &date)
{
    rtc.setTime(&time);
    rtc.setDate(&date);
}

String RClock::getFormattedTime()
{
    rtc_time_t time;
    getTime(time);
    char timeStr[9];
    snprintf(timeStr, sizeof(timeStr), "%02d:%02d:%02d", time.hour, time.min, time.sec);
    return String(timeStr);
}

String RClock::getFormattedDate()
{
    rtc_date_t date;
    getDate(date);
    char dateStr[11];
    snprintf(dateStr, sizeof(dateStr), "%04d-%02d-%02d", date.year, date.mon, date.day);
    return String(dateStr);
}