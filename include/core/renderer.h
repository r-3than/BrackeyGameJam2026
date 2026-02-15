#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <algorithm>

#include "raylib.h"
#include "core/entity.h"

class renderer_t {
private:
    std::vector<entity_t> entities;

private:
    bool compareZ(entity_t i, entity_t j);
public:
    void addEntity(entity_t entity);
    void render();
};


#endif
