#ifndef LEVELLOADER_H
#define LEVELLOADER_H

#include <vector>
#include <algorithm>

#include "raylib.h"
#include "core/entity.h"
#include <string>
#include "level.h"

class levelLoader_t {
public:
    levelLoader_t();
    level_t loadLevel(const char* filePath);
    void writeLevel(const char* filePath);
    void unloadLevel();
    
    
};


#endif