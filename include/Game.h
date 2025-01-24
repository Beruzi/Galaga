#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL2/SDL.h>
#include "Timer.h"
#include "../src/Managers/GameManager.h"
#include "../src/Managers/PlayerManager.h"
/*
#include "PlayerManager.h"
#include "AlienManager.h"
#include "CollisionSystem.h"
*/

/**
 * @brief The core of the Game Logic -- doesn't manage SDL related tasks, 
 * but will handle things like Game Loop, forwarding events to manager, prompting managers
 * to render, etc.
 */
class Game {
private:
    // Managers to be Added
    GameManager& gameManager;
    PlayerManager playerManager;


    // Game state
    enum class GameState { Playing, Paused, Menu };
    GameState currentState;
    bool running;

    Timer timer;

public:
    // Class Basics
    Game(GameManager& gm);
    ~Game();

    // Game Functions
    void run();
    void initManagers();
    void handleInput();
    void update(float dt);
    void render();

    // Event Handling
    void handleImmediateInput(SDL_Event& event);

};

#endif // GAME_H