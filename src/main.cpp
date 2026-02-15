#include <stdio.h>

#include "raylib.h"

int main(int argc, char **argv)
{
    printf("Hello, World!");

    InitWindow(800, 600, "Title");
    SetTargetFPS(60);


    Texture2D ExampleTex = LoadTexture("res/Example.png");
    Rectangle Source = {0.0f, 0.0f, ExampleTex.width, ExampleTex.height}, Dest = {0.0f, 0.0f, 100.0f, 100.0f};
    Vector2 Origin = {0.0f, 0.0f}; float rotation = 0.0f;
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        {
            ClearBackground(RAYWHITE);
            DrawText("Text", 190, 200, 20, LIGHTGRAY);
            for (int i = 0; i < 800; i += 100)
            {
                Dest.x = i;
                DrawTexturePro(ExampleTex, Source, Dest, Origin, rotation, WHITE);                
            }
        }
        EndDrawing();
    }

    UnloadTexture(ExampleTex);
    CloseWindow();

    return 0;
}
