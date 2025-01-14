#ifndef ALIEN_H
#define ALIEN_H 

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "Sprite.h"
#include "Missile.h"

/**
 * @brief General Alien Class to be inherited by Specific Aliens
 */
class Alien : public Sprite {
private:
    std::vector<Missile> missiles;
    int health;

public:
    /**
     * @brief Alien Constructor
     */
    Alien(float x, float y, float w, float h, int hp, SDL_Renderer* renderer);

    /**
     * @brief player fires a shot
     */
    void shoot();

    /**
     * @brief Update the position of all missiles per frame
     * @param dt Delta Time (elapsed time in seconds) for frame independent movement
     */
    void updateMissiles(float dt, SDL_FRect playerWinRect, SDL_FRect alienWinRect);

    /**
     * @brief Loops through all missiles and renders them
     */
    void renderMissiles();
};


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Alien Subclasses
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class Bee : public Alien {
public:
    Bee(float x, float y, float w, float h, int hp, SDL_Renderer* renderer);
};

class Butterfly : public Alien {
public:
    Butterfly(float x, float y, float w, float h, int hp, SDL_Renderer* renderer);
};

class Boss : public Alien {
public:
    Boss(float x, float y, float w, float h, int hp, SDL_Renderer* renderer) ;
};

#endif