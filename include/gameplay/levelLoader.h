#ifndef LEVELLOADER_H
#define LEVELLOADER_H

#include <vector>
#include <algorithm>

#include "raylib.h"
#include "core/entity.h"
#include <string>
#include "level.h"

class levelLoader_t {
private:
    level_t currentLevel;
public:
    levelLoader_t();
    void loadLevel(const char* filePath);
    void writeLevel(const char* filePath);
    void unloadLevel();
    
    
};


#endif