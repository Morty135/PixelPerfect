#ifndef TimeManager_H
#define TimeManager_H

#include <iostream>
#include <raylib.h>

class timeManager
{
    public:
        double DeltaTime;
        double ElapsedTime;
        void UpdateTime();
    private:
        double previousTime = GetTime();
    };



#endif