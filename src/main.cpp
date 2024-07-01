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

    player player;

    Camera2D camera = { 0 };
    camera.target = (Vector2){ player.Pos.x + 20.0f, player.Pos.y + 20.0f };
    camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    camera.zoom = 1.0f;

    SetTargetFPS(30);

    while (!WindowShouldClose())
    {
        timeManager.UpdateTime();
        player.Move(inputManager, timeManager);

        camera.target = (Vector2){ player.Pos.x, player.Pos.y};

        camera.zoom += ((float)GetMouseWheelMove()*0.10f);

        if (camera.zoom > 3.0f) camera.zoom = 3.0f;
        else if (camera.zoom < 0.1f) camera.zoom = 0.1f;

        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode2D(camera);

                player.Draw(inputManager);

                DrawRectangle(0,0,50, 100, BLUE);

            EndMode2D();

            DrawText(TextFormat("Elapsed Time: %.2f", timeManager.ElapsedTime), 10, 10, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}