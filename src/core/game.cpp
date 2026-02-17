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

void gameEngine_t::init()
{
    InitWindow(screenWidth, screenHeight, title);
    SetTargetFPS(60);
    Texture2D *tex = new Texture2D;
    *tex = LoadTexture("res/Example.png");
    image_t *image = new image_t(tex, (Rectangle){0.0f, 0.0f, 32.0f, 32.0f});
    entity_t *entity = new entity_t(image);
    entity_t *entity1 = new entity_t(image);
    entity->properties.push_back(CONTROL);
    entity->x = 100.0f;
    entity->y = 100.0f;
    entity->z = 1.0f;
    renderer.addEntity(*entity);
    renderer.addEntity(*entity1);

    
}

void gameEngine_t::update()
{
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

void gameEngine_t::render(){
    renderer.render();
   
}
