#pragma once
#include <vector>
#include <raylib.h>
#include "gameplay/level.h"
#include "core/entity_defs.h"

class GameManager
{
public:
    // Access point
    static GameManager& instance()
    {
        static GameManager instance; // thread-safe since C++11
        return instance;
    }

    // Delete copy + move
    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;
    GameManager(GameManager&&) = delete;
    GameManager& operator=(GameManager&&) = delete;

    static inline Texture2D tilesheet;
    static inline level_t currentLevel;

    static inline entity_defs_t entityDefs;

    static void init() {
        tilesheet = LoadTexture("res/Example2.png");
        entityDefs = entity_defs_t();
        entityDefs.init();
    }
    
    // Public methods
    void update()
    {
        // do stuff
    }

private:
    GameManager() {}   // private constructor
    ~GameManager() {}  // optional private destructor
};
