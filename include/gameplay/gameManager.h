#pragma once
#include <vector>
#include <raylib.h>
#include <chrono>
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
    static inline int64_t lastTime;
    static inline entity_defs_t entityDefs;

    static void init() {
        lastTime = now_ms();
        tilesheet = LoadTexture("res/Example2.png");
        entityDefs = entity_defs_t();
        entityDefs.init();
    }

    static int64_t now_ms() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    ).count();
    }

    static int64_t deltaTime() {
        int64_t currentTime = now_ms();
        int64_t dt = currentTime - lastTime;
        lastTime = currentTime;
        return dt;
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
