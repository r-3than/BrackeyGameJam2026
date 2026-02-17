#include "core/renderer.h"


renderer_t::renderer_t()
{
    this->entities = nullptr;
}

renderer_t::renderer_t(std::vector<entity_t>* entities)
{
    this->entities = entities;
}

bool renderer_t::compareZ(entity_t i, entity_t j)
{
    return (i.z < j.z);
}

void renderer_t::addEntity(entity_t entity)
{
    entities->push_back(entity);
    std::sort(entities->begin(), entities->end(), compareZ);
}
void renderer_t::addEntity(entity_t* entity)
{
    entities->push_back(entity);
    std::sort(entities->begin(), entities->end(), compareZ);
}
void renderer_t::render()
{
    for (entity_t entity : *entities)
    {
        entity.draw();
    }
}


