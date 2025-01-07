#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL2/SDL.h>

// Forward Declartions
class Sprite;
class Player;
class Timer;

/**
 * @brief The Game object will define all of the overhead needed for executing the game.
 * This includes the core Game Loop, the event loop + queue, rendering, and managing the state of the game
 */
class Game {
private:
    // Core Game Members
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    bool isRunning = false;
    Timer* timer;

    // Game Related Members
    Player* player = nullptr;

public:
    /**
     * @brief Default Constructor
     */ 
    Game();

    /**
     * Destructor
     */
    ~Game();

    /**
     * @brief Main function responsible for running the game.
     * Will start the game loop, event loop, and other primary actions
     */
    void run();
};

#endif 