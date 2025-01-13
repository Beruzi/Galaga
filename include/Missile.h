#ifndef MISSLE_H
#define MISSLE_H

#include <iostream>
#include <algorithm>
#include <SDL2/SDL.h>
#include "Sprite.h"

class Missile : public Sprite {
public:
    /**
     * @brief Default Constructor for Missle
     * @param x X-coordinate of the player.
     * @param y Y-coordinate of the player.
     * @param w Width of the player.
     * @param h Height of the player.
     * @param renderer SDL_Renderer used for rendering.
     */
    Missile(float x, float y, float w, float h, SDL_Renderer* renderer);

    /**
     * @brief Move the missle
     * @param dt Delta Time (elapsed time in seconds) for frame independent movement
     * @returns Returns a bool where false means that the missile position is off the screen
     */
    void fly(float dt);

    /**
     * @brief Simply returns if a missile's position is past the renderable window
     * @returns bool
     */
    bool isOffScreen();

};



#endif