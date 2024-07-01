#include<inputManager.h>

void inputManager::RegisterInput()
{

}


float inputManager::HorizontalAxis()
{
    if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        return 1;
    }
    if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        return -1;
    }
    return 0;
}

float inputManager::VerticalAxis()
{
    if(IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
    {
        return -1;
    }
    if(IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
    {
        return 1;
    }
    return 0;
}