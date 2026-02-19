#include "core/game.h"
#include <raylib.h>
#include "gameplay/gameManager.h"
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
    GameManager::instance().init();
    Texture2D *tex = new Texture2D;
    *tex = LoadTexture("res/ExampleAnimation.png");
    image_t *image = new image_t(tex, (Rectangle){0.0f, 0.0f, 32.0f, 32.0f}, 32);
    Rectangle hitbox = {0, 0, 32, 32};
    entity_t *entity = new entity_t(image, hitbox);
    entity_t *entity1 = new entity_t(image, hitbox);
    entity->properties.push_back(CONTROL);
    entity->properties.push_back(PHYSICS);
    entity->x = 100.0f;
    entity->y = 100.0f;
    entity->z = 1.0f;
    entity->frame = 16;
    renderer.addEntity(*entity);
    entity1->properties.push_back(NOMOVE);
    entity1->x = 100.0f;
    entity1->y = 120.0f;
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


            for (properties_t prop : entity.properties)
            {                
                switch (prop) {
                case PHYSICS:
                    {
                    entity.physics.update(GameManager::instance().deltaTime()/1000.0f);

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

                                        if (entity.properties.end() != std::find(entity.properties.begin(), entity.properties.end(), PHYSICS) ||
                                            entity_other.properties.end() != std::find(entity_other.properties.begin(), entity_other.properties.end(), PHYSICS))
                                        {
                                            entity.physics ^ entity_other.physics;
                                        }

                                        if (entity.properties.end() != std::find(entity.properties.begin(), entity.properties.end(), NOMOVE))
                                        {
                                            entity_other.physics.velocity = {0.0f, 0.0f};
                                            entity.physics.velocity = {0.0f, 0.0f};
                                        }
                                        if (entity_other.properties.end() != std::find(entity_other.properties.begin(), entity_other.properties.end(), NOMOVE))
                                        {
                                            entity_other.physics.velocity = {0.0f, 0.0f};
                                            entity.physics.velocity = {0.0f, 0.0f};
                                        }   
                                    }   
                                }
                            }
                        }

                        

                    entity.x += entity.physics.velocity.x_t;
                    entity.y += entity.physics.velocity.y_t;
                    break;
                    }


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

                                        if (entity.properties.end() != std::find(entity.properties.begin(), entity.properties.end(), PHYSICS) ||
                                            entity_other.properties.end() != std::find(entity_other.properties.begin(), entity_other.properties.end(), PHYSICS))
                                        {
                                            entity.physics ^ entity_other.physics;
                                        }
                                    }   
                                }
                            }
                        }
                    }
                    break;
                }
                case CONTROL:
                    if (IsKeyDown(KEY_W)) entity.physics.velocity.y_t = 2.0f;
                    if (IsKeyDown(KEY_S)) entity.physics.velocity.y_t = -2.0f;
                    if (IsKeyDown(KEY_A)) entity.physics.velocity.x_t = -2.0f;
                    if (IsKeyDown(KEY_D)) entity.physics.velocity.x_t = 2.0f;
                    entity.x += entity.physics.velocity.x_t;
                    entity.y += entity.physics.velocity.y_t;
                    break;
                default:
                
                    break;                
                }  
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
