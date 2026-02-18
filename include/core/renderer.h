#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <algorithm>

#include "raylib.h"
#include "core/entity.h"

class renderer_t {
private:
    std::vector<entity_t>* entities;

private:
    static bool compareZ(entity_t i, entity_t j); 
public:
    renderer_t();
    renderer_t(std::vector<entity_t>* entities);
    void addEntity(entity_t entity);
    void addEntity(entity_t *entity);
    void render(camera_t *camera);
    void render();
};


#endif
