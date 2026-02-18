#include "core/game.h"
#include <raylib.h>

#include <cstdio>

#define collide(a,b) ((a.x < b.x+b.width && a.x+a.width > b.x)&&(a.y < b.y+b.height && a.y+a.height > b.y))

gameEngine_t::gameEngine_t(int screenWidth, int screenHeight, const char* title)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    this->title = title;
    this->entities = std::vector<entity_t>();
    this->renderer = renderer_t(&entities);
    frameCount = 0;
    
    camera = new_camera();
}

void gameEngine_t::init()
{
    InitWindow(screenWidth, screenHeight, title);
    SetTargetFPS(60);
    Texture2D *tex = new Texture2D;
    *tex = LoadTexture("res/ExampleAnimation.png");
    image_t *image = new image_t(tex, (Rectangle){0.0f, 0.0f, 32.0f, 32.0f}, 32);
    Rectangle hitbox = {0, 0, 32, 32};
    entity_t *entity = new entity_t(image, hitbox);
    entity_t *entity1 = new entity_t(image, hitbox);
    entity->properties.push_back(CONTROL);
    entity->x = 100.0f;
    entity->y = 100.0f;
    entity->z = 1.0f;
    entity->frame = 16;
    renderer.addEntity(*entity);
    entity1->x = 100.0f;
    entity1->y = 100.0f;
    renderer.addEntity(*entity1);
}

void gameEngine_t::update()
{
    while (!WindowShouldClose())
    {
        if (!IsKeyDown(KEY_Z))
        {           
            if (IsKeyDown(KEY_RIGHT)) camera->position.x -= 2.0f;
            if (IsKeyDown(KEY_LEFT)) camera->position.x += 2.0f;
            if (IsKeyDown(KEY_UP)) camera->position.y += 2.0f;
            if (IsKeyDown(KEY_DOWN)) camera->position.y -= 2.0f;
        } else {
            if (IsKeyDown(KEY_RIGHT)) camera->zoom.w -= 2.0f;
            if (IsKeyDown(KEY_LEFT)) camera->zoom.w += 2.0f;
            if (IsKeyDown(KEY_UP)) camera->zoom.h += 2.0f;
            if (IsKeyDown(KEY_DOWN)) camera->zoom.h -= 2.0f;
        }
        for (entity_t &entity : entities)
        {
            if (frameCount % 60 == 0) entity.frame++;
            if (entity.y+64.0f <= screenHeight) entity.y += 1.2f; // TODO: GRAVITY
            for (properties_t prop : entity.properties)
            {                
                switch (prop) {
                case COLLIDE:
                {                    
                    for (entity_t &entity_other : entities) {
                        if (&entity_other != &entity) {
                            for (properties_t prop_other : entity_other.properties)
                            {
                                if (prop_other == COLLIDE)
                                {
                                    Rectangle hitbox, hitbox_other;
                                    hitbox = entity.getHitbox();
                                    hitbox_other = entity_other.getHitbox();
                                    //printf("hitbox: {%f, %f, %f, %f}\n", hitbox.x, hitbox.y, hitbox.width, hitbox.height);
                                    //printf("hitbox_other: {%f, %f, %f, %f}\n", hitbox_other.x, hitbox_other.y, hitbox_other.width, hitbox_other.height);
                                    //check aabb collision
                                    if (collide(hitbox, hitbox_other))
                                    {
                                        // TODO: IMPLEMENT THIS CORECTLY (ETHAN) p.s. ty :)
                                        // momentum speed mass acceleration...

                                        
                                        const int div = 25;
                                        const float diffx = hitbox.x-hitbox_other.x;
                                        entity.x+=diffx/(2*div);
                                        entity_other.x-=diffx/(2*div);

                                        const float diffy = hitbox.y-hitbox_other.y;
                                        entity.y+=diffy/(2*div);
                                        entity_other.y-=diffy/(2*div);
                                    }   
                                }
                            }
                        }
                    }
                    break;
                }
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
        DrawFPS(0, 0);
        EndDrawing();
        frameCount++;
    }
}

void gameEngine_t::render(){
    renderer.render(camera);
   
}
