#include "levelLoader.h"

levelLoader_t::levelLoader_t(){}

void levelLoader_t::loadLevel(const char* filePath) {

    // Load level data from the specified file path
    // For example, you can read a JSON or XML file and populate the currentLevel struct
}

void levelLoader_t::unloadLevel() {
    // Unload the current level and free any resources if necessary
    // For example, you can clear the textures, images, and entities vectors in the currentLevel struct
}

void levelLoader_t::writeLevel(const char* filePath) {
    // Write the current level data to the specified file path
    // For example, you can serialize the currentLevel struct to a JSON or XML file
}