#pragma once
#include <vector>
#include <raylib.h>
#include "gameplay/level.h"

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

    static Texture2D tilesheet;
    static level_t currentLevel;

    static void init() {
        tilesheet = LoadTexture("res/Example2.png");
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
