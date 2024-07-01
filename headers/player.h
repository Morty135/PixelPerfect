#ifndef Player_H
#define Player_H

#include <iostream>
#include <raylib.h>
#include <raymath.h>

#include <inputManager.h>
#include <timeManager.h>

class player
{
    public:
        player();
        void Draw(inputManager inputManager);
        void Move(inputManager inputManager, timeManager timeManager);

        Vector2 Pos = (Vector2){0.0,0.0};
    private:
        bool flipped = false;
        bool up = false;

        int currentFrame = 0;
        int framesCounter = 0;
        int framesSpeed = 8;

        Rectangle frameRec;

        Texture2D playerRunDown = LoadTexture("resources/player_run_down.png");
        Texture2D playerRunUp = LoadTexture("resources/player_run_up.png");
    };



#endif