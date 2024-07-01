#include<timeManager.h>



void timeManager::UpdateTime() 
{
    double currentTime = GetTime(); 
    double deltaTime = currentTime - previousTime;
    previousTime = currentTime;
    timeManager::DeltaTime = deltaTime;
    timeManager::ElapsedTime = currentTime;
}