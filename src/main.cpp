#include <stdio.h>

#include "core/game.h"

int main(int argc, char **argv)
{
    printf("Hello, World!");
    gameEngine_t game = gameEngine_t(800, 600, "My Game");
    game.init();
    game.update();
    
    
    return 0;
}
