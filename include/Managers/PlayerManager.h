#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include <iostream>
#include <SDL2/SDL.h>
#include "GameManager.h"
#include "Player.h"
#include "Missile.h"


class PlayerManager {
private:
    GameManager& gameManager;

    Player* player;
    std::vector<Missile> missiles; 

public:
    // Class Basics
    PlayerManager(GameManager& gm); 
    ~PlayerManager();

    // Player Management
    void initPlayer();
    void handleImmediateInput(SDL_Event& event);
    void handleContinousInput(float dt);

    // Missile Management
    void shoot();
    void updateMissiles(float dt);
    void renderMissiles();

    // Updating
    void update(float dt);
    
    // Rendering
    void render();
};
#endif // PLAYERMANAGER_H