#ifndef ALIENMANAGER_H
#define ALIENMANAGER_H

#include <iostream>
#include <SDL2/SDL.h>
#include "GameManager.h"
#include "Alien.h"
#include "Missile.h"

class AlienManager {
private:
    GameManager& gameManager;

    std::vector<std::vector<Alien>> aliens;
    std::vector<Missile> missiles;

public:
    // Class Basics
    AlienManager(GameManager& gm); 
    ~AlienManager();

    // Alien Management
    void initAliens(int rows, int cols);
    void moveAliens(float dt);

    // Missile Management
    void shoot(const Alien& alien);
    void updateMissiles(float dt);
    void renderMissiles();

    // Updating
    void update(float dt);
    
    // Rendering
    void render();
};

#endif // ALIENMANAGER_H