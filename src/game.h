#include <iostream>
#include <SDL2/SDL.h>
#include "player.h"

/**
 * @brief The Game object will define all of the overhead needed for executing the game.
 * This includes the core Game Loop, the event loop + queue, and managing the state of the game
 */
class Game
{
private:
    // Core Priate Members
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    bool isRunning = false;
    Player* player = nullptr;

public:
    // Default Constructor
    Game() {
        // Initialize SDL
        if(SDL_Init(SDL_INIT_VIDEO) < 0) { 
            std::cout << "SDL could not be intialized" << SDL_GetError() <<  std::endl;

        } 
        else {
            std::cout << "SDL is ready to go" << std::endl;
        }


        // Initialize the Winow and Renderer
        window = SDL_CreateWindow(
            "Galaga",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            480,
            640,
            SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

        // Load the Sprite sheet
        Sprite::LoadSpriteSheet(renderer, "../assets/Sprites/SpriteSheet.bmp");

        // Create the player
        player = new Player(240 - 15, 600 - 16, 15, 16, renderer);
    }
    // Destructor
    ~Game(){
        // Clean up my resources
        delete player;
        // Clean up SDL resources
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
public:
    /**
     * @brief Main function responsible for running the game.
     * Will start the game loop, event loop, and other primary actions
     */
    void run() {
        SDL_Event event;
        isRunning = true;

        while (isRunning) {
            while (SDL_PollEvent(&event)) {
                // Quit Event
                if (event.type == SDL_QUIT) {
                    isRunning = false;
                }
                // Player event
                player->handleInput(event);
            }

            // Render Updates
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            player->Render();

            SDL_RenderPresent(renderer);
        }
    }

};