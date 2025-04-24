#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <SDL2/SDL.h>


/**
 * @brief Controls Game Loop, Initializes SDL, Delegates Subsystems
 */
class GameEngine {
private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    bool isRunning = false;

    // Managers and Sub-Systems
        // Entity Manager
        // Timer
        // Scene Manager
        // Input System
        // Audio System
        // Collision System
        // Render System
        // Config (Game Constants)
    

public:
    // Class Basics
    GameEngine();
    ~GameEngine();

    // Initialize SDL Resources
    bool init();
    void initWindow();
    void initRenderer();

    // Engine
    void run();
    void shutdown();

    
};
#endif // ENGINE_H