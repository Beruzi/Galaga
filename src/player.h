#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SDL2/SDL.h>
#include "Sprite.h"

/**
 * @brief Handles all things player. 
*/
class Player : public Sprite {
public:
    /**
     * @brief Constructor, will initialize the SDL_FRect and srcRect for sprites amongst other things
     * @param x X-coordinate of the player.
     * @param y Y-coordinate of the player.
     * @param w Width of the player.
     * @param h Height of the player.
     * @param renderer SDL_Renderer used for rendering.
     */
    Player(float x, float y, float w, float h, SDL_Renderer* renderer);


    /**
     * @brief Handles the movement inputs (WASD)... this uses the keyboard state rather than the event'
     * to bypass the 'repeated key delay' that the OS imposes
     * @param dt Delta Time (elapsed time in seconds) for frame independent movement
     */
    void processMovement(float dt);

    /**
     * @brief player fires a shot
     */
    void shoot();

    /**
     * @brief Enforces the player stays within the window bounds with a border padding. 
     * Padding is currently set at '5' pixels.
     *  
     */    
    void enforceBounds();
};

#endif 