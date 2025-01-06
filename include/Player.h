#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "Sprite.h"
#include "Missile.h"

/**
 * @brief Handles all things player. 
*/
class Player : public Sprite {
private:
    std::vector<Missile> missiles;
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
     * @brief Handles a discrete event by the player
     * @param dt Delta Time (elapsed time in seconds) for frame independent movement
     * @
     */
    void handleImmediateInput(SDL_Event& event);

    /**
     * @brief Primarily handles the movement inputs (WASD), but this will be used to monitor 
     * keyboard state rather than a discrete event happening
     * @param dt Delta Time (elapsed time in seconds) for frame independent movement
     */
    void handleContinousInput(float dt);

    /**
     * @brief Enforces the player stays within the window bounds with a border padding. 
     * Padding is currently set at '5' pixels.
     *  
     */    
    void enforceBounds();

    /**
     * @brief player fires a shot
     */
    void shoot();

    /**
     * @brief Update the position of all missiles per frame
     * @param dt Delta Time (elapsed time in seconds) for frame independent movement
     */
    void updateMissiles(float dt);

    /**
     * @brief Loops through all missiles and renders them
     */
    void renderMissiles();
    
};

#endif 