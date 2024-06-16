#ifndef STAGE_MANAGER_H
#define STAGE_MANAGER_H

#include <vector>
#include "Display.h"

class StageManager {
public:
    StageManager();
    ~StageManager();

    Display* addStage(int width, int height);
    void switchStage(int index);
    void renderStage(int index, int posX, int posY, m5epd_update_mode_t updateMode);

    Display& getCurrentDisplay();
    Display& getDisplay(int index);

private:
    std::vector<Display*> stages;
    int currentStageIndex;
};

#endif // STAGE_MANAGER_H