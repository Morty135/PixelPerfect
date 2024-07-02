#include <player.h>


player::player(int screenWidth, int screenHeight)
{
    playerRunDown.width = playerRunDown.width * 4;
    playerRunDown.height = playerRunDown.height * 4;
    playerRunUp.width = playerRunUp.width * 4;
    playerRunUp.height = playerRunUp.height * 4;

    player::frameRec = { 0.0f, 0.0f, (float)playerRunDown.width/4, (float)playerRunDown.height };

    player::camera.target = (Vector2){ player::Pos.x , player::Pos.y };
    player::camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    player::camera.zoom = 1.0f;
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

    Vector2 correctedPlayerPos = Vector2Add(player::Pos, {-30,-40});
    if (inputManager.VerticalAxis() > 0)
    {
        DrawTextureRec(playerRunDown, frameRec, correctedPlayerPos, WHITE);
    }
    else if (inputManager.VerticalAxis() < 0)
    {
        DrawTextureRec(playerRunUp, frameRec, correctedPlayerPos, WHITE);
    }
    else
    {
        DrawTextureRec(playerRunDown, frameRec, correctedPlayerPos, WHITE);
    }
}



void player::Move(inputManager inputManager, timeManager timeManager)
{
    camera.target = (Vector2){ player::Pos.x, player::Pos.y};

    camera.zoom += ((float)GetMouseWheelMove()*0.10f);

    if (camera.zoom > 3.0f) camera.zoom = 3.0f;
    else if (camera.zoom < 0.1f) camera.zoom = 0.1f;


    Vector2 Movement = {inputManager.HorizontalAxis(), inputManager.VerticalAxis()};
    Movement = Vector2Normalize(Movement);  

    double movementSpeed = 200;
    player::Pos.x += Movement.x * movementSpeed * timeManager.DeltaTime;  
    player::Pos.y += Movement.y * movementSpeed * timeManager.DeltaTime;
}