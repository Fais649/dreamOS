#ifndef APPTASKCLASS_H
#define APPTASKCLASS_H

#include "TaskClass.h"
#include "DisplayConstants.h"

class AppTaskClass : public TaskClass
{
public:
    AppTaskClass(const char *name, UBaseType_t priority, uint32_t stackSize, uint8_t taskCore);
    virtual void start()
    {
        initDisplay();
        TaskClass::start();
    }

    virtual void stop()
    {
        if (taskHandle != nullptr)
        {
            save();
        }
        TaskClass::stop();
    };


    void drawLoading()
    {
        display.getCanvas().deleteCanvas();
        display.createCanvas(60, 20);
        display.clear();
        display.setTextSize(2);
        display.drawString("****", 0, 0);
        display.pushCanvas(480, 10, UPDATE_MODE_DU4);
    }

protected:
    virtual void
    taskFunction() = 0;

    virtual void save() {};

    virtual void initDisplay()
    {
        display.getCanvas().deleteCanvas();
        display.createCanvas(DISPLAY_CANVAS_WIDTH, DISPLAY_CANVAS_HEIGHT);
        display.clear();

        drawBackground();
        drawLogo();
        drawDate();
        drawTitle();

        display.pushCanvas(BACKGROUND_X, BACKGROUND_Y, UPDATE_MODE_GC16);
        display.getCanvas().deleteCanvas();
    };

    virtual void drawBackground()
    {
        display.fillRoundRect(BACKGROUND_SHADOW_X, BACKGROUND_SHADOW_Y, BACKGROUND_BOX_WIDTH, BACKGROUND_BOX_HEIGHT, BACKGROUND_BOX_CORNER_RADIUS, M5EPD_GREY);
        display.fillRoundRect(BACKGROUND_BOX_X, BACKGROUND_BOX_Y, BACKGROUND_BOX_WIDTH, BACKGROUND_BOX_HEIGHT, BACKGROUND_BOX_CORNER_RADIUS, M5EPD_BLACK);
        display.fillRoundRect(BACKGROUND_BOX_X + BACKGROUND_BOX_BORDER, BACKGROUND_BOX_Y + BACKGROUND_BOX_BORDER, BACKGROUND_BOX_WIDTH - (BACKGROUND_BOX_BORDER * 2), BACKGROUND_BOX_HEIGHT - (BACKGROUND_BOX_BORDER * 2), BACKGROUND_CONTENT_CORNER_RADIUS, M5EPD_WHITE);
    };

    virtual void drawTitle()
    {
        display.setTextSize(DISPLAY_TITLE_SIZE);
        String title = String(taskName) + ";";
        display.drawString(title, DISPLAY_TITLE_X, DISPLAY_TITLE_Y);
    };

    virtual void drawLogo()
    {
        display.fillCircle(DISPLAY_LOGO_X, DISPLAY_LOGO_Y, DISPLAY_LOGO_RADIUS, M5EPD_BLACK);
        display.fillCircle(DISPLAY_LOGO_X + DISPLAY_LOGO_GAP, DISPLAY_LOGO_Y, DISPLAY_LOGO_RADIUS, M5EPD_BLACK);
        display.fillCircle(DISPLAY_LOGO_X, DISPLAY_LOGO_Y + DISPLAY_LOGO_GAP, DISPLAY_LOGO_RADIUS, M5EPD_BLACK);
    };

    virtual void drawDate()
    {
        rtc_date_t date;
        rclock.getDate(date);
        String dateStr = String(date.day) + "-" + String(date.mon) + "-" + String(date.year);
        display.setTextSize(DISPLAY_DATE_SIZE);
        display.drawString("/" + dateStr, DISPLAY_DATE_X, DISPLAY_DATE_Y);
    };

    virtual void updateDisplay() = 0;

private:
};

#endif // TASKCLASS_H