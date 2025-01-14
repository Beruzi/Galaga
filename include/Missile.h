#ifndef MISSILE_H
#define MISSILE_H


#include <iostream>
#include <algorithm>
#include <SDL2/SDL.h>
#include "Sprite.h"

class Missile : public Sprite {
public:
    /**
     * @brief Default Constructor for Missile
     * @param x X-coordinate of the sprite shooting the missile
     * @param y Y-coordinate of the sprite shooting the missile
     * @param w Width of the missile
     * @param h Height of the missile
     * @param renderer SDL_Renderer used for rendering.
     */
    Missile(float x, float y, float w, float h, SDL_Renderer* renderer);

    /**
     * @brief Move the missle forwards... meant for the player's missiles
     * @param dt Delta Time (elapsed time in seconds) for frame independent movement
     * @returns Returns a bool where false means that the missile position is off the screen
     */
    void fly(float dt);

    /**
     * @brief Overloaded Fly Function meant for Aliens... will shoot AT the player
     */
    void fly(float dt, const SDL_FRect& playerWinRect, const SDL_FRect& alienWinRect);

    /**
     * @brief Simply returns if a missile's position is past the renderable window
     * @returns bool
     */
    bool isOffScreen();

};



#endif