#ifndef LEVEL_EDITOR_H
#define LEVEL_EDITOR_H
#include "core/game.h"

class levelEditor_t {
private:
    int screenWidth;
    int screenHeight;
    const char* title;
    renderer_t renderer;
    std::vector<entity_t> entities;
public:
    levelEditor_t(int screenWidth = 800, int screenHeight = 600, const char* title = "Brackey Game Jam 2026");
    void init();
    void update();
    void render();
    void saveLevel(const char* filePath);
    void loadLevel(const char* filePath);
};


#endif