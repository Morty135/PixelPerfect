#include <player.h>


player::player()
{
    playerRunDown.width = playerRunDown.width * 4;
    playerRunDown.height = playerRunDown.height * 4;
    playerRunUp.width = playerRunUp.width * 4;
    playerRunUp.height = playerRunUp.height * 4;

    player::frameRec = { 0.0f, 0.0f, (float)playerRunDown.width/4, (float)playerRunDown.height };
}



void player::Draw(inputManager inputManager)
{
    framesCounter++;

    if (framesCounter >= (30/framesSpeed))
    {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 3) currentFrame = 0;

        frameRec.x = (float)currentFrame*(float)playerRunDown.width/4;
    }

    if (inputManager.HorizontalAxis() > 0)
    {
        if(!flipped)
        {
            playerRunDown.width = -playerRunDown.width;
            playerRunUp.width = -playerRunUp.width;
            flipped = true;
        }
    }
    else
    {
        if (flipped)
        {
            playerRunDown.width = -playerRunDown.width;
            playerRunUp.width = -playerRunUp.width;
            flipped = false;
        }
    }

    if (inputManager.VerticalAxis() > 0)
    {
        DrawTextureRec(playerRunDown, frameRec, player::Pos, WHITE);
    }
    else if (inputManager.VerticalAxis() < 0)
    {
        DrawTextureRec(playerRunUp, frameRec, player::Pos, WHITE);
    }
    else
    {
        DrawTextureRec(playerRunDown, frameRec, player::Pos, WHITE);
    }
}



void player::Move(inputManager inputManager, timeManager timeManager)
{
    Vector2 Movement = {inputManager.HorizontalAxis(), inputManager.VerticalAxis()};
    Movement = Vector2Normalize(Movement);  

    double movementSpeed = 200;
    player::Pos.x += Movement.x * movementSpeed * timeManager.DeltaTime;  
    player::Pos.y += Movement.y * movementSpeed * timeManager.DeltaTime;
}