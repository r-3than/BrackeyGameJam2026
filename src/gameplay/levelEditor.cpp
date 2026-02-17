#include "gameplay/levelEditor.h"
#include "gameplay/gameManager.h"
#include <raylib.h>
#include <iostream>
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
        entities.push_back(*entity);
    }

}

void levelEditor_t::update() {
    Vector2 mouseClickPosition;
    entity_t selectedEntity = entity_t(nullptr);
    while (!WindowShouldClose())
    {
        mouseClickPosition = GetMousePosition();
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            std::cout << "Mouse Clicked at: " << mouseClickPosition.x << ", " << mouseClickPosition.y << std::endl;
            for (entity_t& entity : entities) {
                if (CheckCollisionPointRec(mouseClickPosition, (Rectangle){entity.x, entity.y, 32.0f, 32.0f})) {
                    selectedEntity = entity;
                    std::cout << "Selected Entity at: " << entity.x << ", " << entity.y << std::endl;
                }
            }
        }
        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
            entity_t* newEntity = new entity_t(*GameManager::instance().entityDefs.entities[0]);
            newEntity->setImage(selectedEntity.getImage());
            newEntity->x = ((int)mouseClickPosition.x/32)*32;
            newEntity->y = ((int)mouseClickPosition.y/32)*32;

            entities.push_back(*newEntity);
        }
        if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE)) {
            entity_t* newEntity = new entity_t(*GameManager::instance().entityDefs.entities[0]);
            newEntity->setImage(selectedEntity.getImage());
            newEntity->x = ((int)mouseClickPosition.x/32)*32;
            newEntity->y = ((int)mouseClickPosition.y/32)*32;

            entities.push_back(*newEntity);
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