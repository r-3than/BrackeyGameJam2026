#include "gameplay/levelEditor.h"
#include "gameplay/gameManager.h"
#include <raylib.h>
levelEditor_t::levelEditor_t(int screenWidth, int screenHeight, const char* title) {
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    this->title = title;
    this->entities = std::vector<entity_t>();
    this->renderer = renderer_t(&entities);
    
}

void levelEditor_t::init() {
    InitWindow(screenWidth, screenHeight, title);
    SetTargetFPS(60);
    GameManager::instance().init();
    float x = 0.0f;
    for (entity_t* entity : GameManager::instance().entityDefs.entities) {
        entity->x = x;
        x += 32.0f;
        renderer.addEntity(*entity);
    }

}

void levelEditor_t::update() {
    while (!WindowShouldClose())
    {
        for (entity_t &entity : entities)
        {
            for (properties_t prop : entity.properties)
            {                
                switch (prop) {
                case CONTROL:
                    if (IsKeyDown(KEY_W)) entity.y -= 2.0f;
                    if (IsKeyDown(KEY_S)) entity.y += 2.0f;
                    if (IsKeyDown(KEY_A)) entity.x -= 2.0f;
                    if (IsKeyDown(KEY_D)) entity.x += 2.0f;
                    break;
                default:
                
                    break;                
                }            
            }
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        render();
        EndDrawing();
        // Update game logic here
    }
    // Update game logic here
}

void levelEditor_t::render() {
    renderer.render();
}

void levelEditor_t::saveLevel(const char* filePath) {}

void levelEditor_t::loadLevel(const char* filePath) {}