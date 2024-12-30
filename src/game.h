#include <iostream>
#include <SDL2/SDL.h>

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

public:
    // Default Constructor
    Game() {
        // Initialize SDL
        if(SDL_Init(SDL_INIT_VIDEO) < 0){ 
            std::cout << "SDL could not be intialized" << SDL_GetError() <<  std::endl;

        } else{
            std::cout << "SDL is ready to go" << std::endl;
        }


        // Define the Window
        window = SDL_CreateWindow(
            "Galaga",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            480,
            640,
            SDL_WINDOW_SHOWN);

        // Define the Rendered
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }
    // Destructor
    ~Game()
    {
        // Clean up SDL Resources
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

private:
    bool isRunning = false;

public:
    /**
     * @brief Main function responsible for running the game.
     * Will start the game loop, event loop, and other primary actions
     */
    void run() {
        SDL_Event event;
        isRunning = true;

        // Start Game Loop
        while (isRunning) {

            // Event Loop
            while (SDL_PollEvent(&event)) {
                // Check if Quit Event Occurs
                if (event.type == SDL_QUIT) {
                    isRunning = false;
                }
                std::cout << event.type << std::endl;
            }
        }
    }
};