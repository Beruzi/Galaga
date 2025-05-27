#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <iostream>
#include <SDL2/SDL.h>

#include "RenderSystem.h"
#include "Timer.h"
#include "InputSystem.h"
#include "Player.h"

/**
 * @brief Controls Game Loop, Initializes SDL, Delegates Subsystems
 */
class GameEngine {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;

    // Managers and Sub-Systems
    RenderSystem* renderSystem;
    Timer* timer;
    InputSystem* inputSystem;
        // Entity Manager
        // Scene Manager
        // Input System
        // Audio System
        // Collision System
        // Config (Game Constants)
    

public:
    // Class Basics
    GameEngine();
    ~GameEngine();

    // Initialize SDL Resources
    void init();
    void initWindow();
    void initRenderer();

    // Engine
    void run();
    void shutdown();

    
};
#endif // GAMEENGINE_H