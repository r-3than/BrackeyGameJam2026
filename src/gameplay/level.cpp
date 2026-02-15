
#include <vector>
#include <string>
#include <cereal/types/unordered_map.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/archives/binary.hpp>

#include "core/entity.h"
#include <algorithm>
#include "level.h"





void level_t::load() {

    Texture2D tex = LoadTexture("res/Example.png");
    image_t image = image_t(&tex, (Rectangle){0.0f, 0.0f, 32.0f, 32.0f});
    entity_t entity = entity_t(&image);
    // Load level data here (e.g., from a file)
}

void level_t::addEntity(entity_t entity) {
    data.entities.push_back(entity);
}

void level_t::addTexture(std::string filePath) {

    Texture2D texture = LoadTexture(filePath.c_str());
    data.textures.push_back(texture);
}

void level_t::addImage(image_t image) {
    data.images.push_back(image);
}

void level_t::addEntity(entity_t entity) {
    data.entities.push_back(entity);
}




