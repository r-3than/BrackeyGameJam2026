#include <stdio.h>

#include "core/game.h"
#include "gameplay/levelEditor.h"

int main(int argc, char **argv)
{
    printf("Hello, World!");

    //levelEditor_t editor = levelEditor_t(800, 600, "My Game");
    //editor.init();
    //editor.update();

    gameEngine_t game = gameEngine_t(800, 600, "My Game");
    game.init();
    game.update();
    
    
    return 0;
}

