#include "Game.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Basic Class
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Game::Game(GameManager& gm) : 
    gameManager(gm),
    playerManager(gm),
    alienManager(gm),
    /* Initialize other Managers,*/
    running(false), 
    currentState(GameState::Playing), 
    timer() {}


Game::~Game() {}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Game Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Game::run() {
    initManagers();

    running = true;
    SDL_Event event;
    float dt;

    while(running) {
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            handleImmediateInput(event);
        }
        // Find delta time
        timer.tick();
        dt = timer.getDeltaTime();

        // Make Game Updates
        update(dt);

        // Render all Game Entities
        render();
        std::cout << "Delta time: " << dt << " seconds" << std::endl;
    }
}

void Game::initManagers() {
    playerManager.initPlayer();
    // adjust the initialization to have the real alien layout
    alienManager.initAliens(1,1);
}

void Game::update(float dt) {
    playerManager.update(dt);
    alienManager.update(dt);
}

void Game::render() {
    SDL_SetRenderDrawColor(gameManager.getRenderer(), 0, 0, 0, 255);
    SDL_RenderClear(gameManager.getRenderer());

    playerManager.render();
    alienManager.render();

    SDL_RenderPresent(gameManager.getRenderer());
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Event Handling
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Game::handleImmediateInput(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
        switch (event.key.keysym.sym) {
            case SDLK_p:
                currentState = GameState::Paused;
                break;
            case SDLK_ESCAPE:
                currentState = GameState::Paused;
                // prompt quick escape screen
                break;
            default:
                playerManager.handleImmediateInput(event);
        }
    }
}
