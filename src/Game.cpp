#include "Game.h"
#include "Player.h"
#include "Timer.h"
#include "Sprite.h"

Game::Game() {
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
        SDL_WINDOW_SHOWN
    );
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

    // Load the Sprite sheet
    Sprite::LoadSpriteSheet(renderer, "../assets/Sprites/SpriteSheet.bmp");

    // Start Timer
    timer = new Timer();

    // Create the player
    player = new Player(240 - 15, 600 - 16, 15, 16, renderer);
}

Game::~Game() {
    // Clean up resources
    delete player;
    delete timer;

    // Clean up SDL resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Game::run() {
    SDL_Event event;
    isRunning = true;

    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            // Quit Event
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }
        }

        // Update Timer
        timer->Tick();
        float dt = timer->getDeltaTime();

        // Player event
        player->processMovement(dt);

        // Render Updates
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        player->Render();
        SDL_RenderPresent(renderer);
    }
}
