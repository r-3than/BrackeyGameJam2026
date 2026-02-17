#ifndef ENTITY_DEFS_H
#define ENTITY_DEFS_H
#include <vector>
#include <string>
#include "core/entity.h"

class entity_defs_t {
public:
    std::vector<entity_t*> entities;
    std::vector<image_t*> images;
    std::vector<std::string> entity_name;
    void init();
};

#endif