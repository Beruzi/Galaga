#ifndef MISSILE_H
#define MISSILE_H


#include <iostream>
#include <algorithm>
#include <SDL2/SDL.h>
#include "Sprite.h"

class Missile : public Sprite {
public:
    Missile();

    void fly(float dt);

    void fly(float dt, const SDL_FRect& playerWinRect, const SDL_FRect& alienWinRect);

    bool isOffScreen();

};

#endif