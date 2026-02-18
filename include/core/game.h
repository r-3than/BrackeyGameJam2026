#ifndef GAME_H
#define GAME_H
#include <vector>
#include "core/renderer.h"
#include "core/camera.h"

class gameEngine_t {
private:
    int screenWidth;
    int screenHeight;
    const char* title;
    int frameCount;
    
    renderer_t renderer;
    camera_t *camera;
    std::vector<entity_t> entities;
public:
    gameEngine_t(int screenWidth = 800, int screenHeight = 600, const char* title = "Brackey Game Jam 2026");
    void init();
    void update();
    void render();
};



#endif
