#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include <string>

#include "core/entity.h"
#include <algorithm>

struct level_data_t {
    
    std::vector<Texture2D> textures;
    std::vector<image_t> images;
    std::vector<entity_t> entities;

    template<class Archive>
    void serialize(Archive& archive)
    {
        archive(entities);
    }
}; 


struct level_t {
    const char* name;
    level_data_t data;

    void load();

    void addEntity(entity_t entity);

    void addTexture(std::string filePath);

    void addImage(image_t image);

    void addEntity(entity_t entity);

};

#endif
