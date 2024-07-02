#include <raylib.h>
#include <raymath.h>
#include <iostream>

#include <inputManager.h>
#include <timeManager.h>
#include <player.h>


int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "PixelPerfect");
    inputManager inputManager;
    timeManager timeManager;

    player player(screenWidth, screenHeight);

    SetTargetFPS(30);

    while (!WindowShouldClose())
    {
        timeManager.UpdateTime();
        player.Move(inputManager, timeManager);

        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode2D(player.camera);

                player.Draw(inputManager);

                DrawRectangle(0,0, 4, 4, BLUE);
                DrawRectangle(4, 4, 4, 4, GREEN);

            EndMode2D();

            DrawText(TextFormat("Elapsed Time: %.2f", timeManager.ElapsedTime), 10, 10, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}