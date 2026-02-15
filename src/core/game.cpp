#include "core/game.h"
#include <raylib.h>


gameEngine_t::gameEngine_t(int screenWidth, int screenHeight, const char* title)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    this->title = title;
    this->entities = std::vector<entity_t>();
    this->renderer = renderer_t(&entities);
}

void gameEngine_t::init(){

    Texture2D tex = LoadTexture("res/Example.png");
    image_t image = image_t(&tex, (Rectangle){0.0f, 0.0f, 32.0f, 32.0f});
    entity_t entity = entity_t(&image);
    entity.x = 100.0f;
    entity.y = 100.0f;
    entity.z = 0.0f;
    renderer.addEntity(entity);

    InitWindow(screenWidth, screenHeight, title);
    SetTargetFPS(60);
}

void gameEngine_t::update(){
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        render();
        EndDrawing();
        // Update game logic here
    }
    // Update game logic here
}

void gameEngine_t::render(){
    renderer.render();
   
}