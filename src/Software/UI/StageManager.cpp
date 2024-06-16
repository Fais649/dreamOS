#include "StageManager.h"

StageManager::StageManager() : currentStageIndex(0) {}

// StageManager::~StageManager() {
//     for (auto stage : stages) {
//         delete stage;
//     }
// }

// Display* StageManager::addStage(int width, int height) {
//     Display* newStage = new Display();
//     newStage->createCanvas(width, height);
//     stages.push_back(newStage);
//     return newStage;
// }

// void StageManager::switchStage(int index) {
//     if (index >= 0 && index < stages.size()) {
//         currentStageIndex = index;
//     } else {
//         Serial.println("Invalid stage index");
//     }
// }

// Display& StageManager::getCurrentDisplay() {
//     if (currentStageIndex >= 0 && currentStageIndex < stages.size()) {
//         return *stages[currentStageIndex];
//     } else {
//         Serial.println("Invalid current stage index");
//         while (1); // Halt execution if index is invalid
//     }
// }

// Display& StageManager::getDisplay(int index) {
//     if (index >= 0 && index < stages.size()) {
//         return *stages[index];
//     } else {
//         Serial.println("Invalid stage index");
//         while (1); // Halt execution if index is invalid
//     }
// }

// void StageManager::renderStage(int index, int posX, int posY, m5epd_update_mode_t updateMode) {
//     if (index >= 0 && index < stages.size()) {
//         stages[index]->pushCanvas(posX, posY, updateMode); // Assuming UPDATE_MODE_GC16 is the correct mode
//     } else {
//         Serial.println("Invalid current stage index");
//     }
// }