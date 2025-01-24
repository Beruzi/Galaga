#ifndef MISSILE_H
#define MISSILE_H

#include <iostream>
#include <algorithm>
#include <SDL2/SDL.h>
#include "Sprite.h"

/**
 * @brief Represents a missile shot by a player or alien.
 */
class Missile : public Sprite {
private:
    float speed;

public:
    // Class Basics
    Missile(float x, float y, int speed);

    // Missile Movement
    void fly(float dt); // player overload
    void fly(float dt, const SDL_FRect& target); // alien overload

    // Utility
    bool isOffScreen() const; 
};

#endif // MISSILE_H
