#ifndef InputManager_H
#define InputManager_H

#include <iostream>
#include <raylib.h>

class inputManager
{
    public:
        void RegisterInput();

        float HorizontalAxis();
        float VerticalAxis();
    };



#endif