#include "Engine.h"


// -------------------------------------------
// Class Basics
// -------------------------------------------
GameEngine::GameEngine() 
    : window(nullptr), renderer(nullptr), isRunning(false) {}

GameEngine::~GameEngine() {
    shutdown();
}


// -------------------------------------------
// Intialize SDL Resources
// -------------------------------------------
bool GameEngine::init() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Quit();
        throw std::runtime_error("SDL_Init Failed" + std::string(SDL_GetError()));
    }
    else {
        std::cout << "SDL Ready to go" << std::endl;
    }

    // Initialize SDL Resources
    initWindow();
    initRenderer();

    // Initialize Managers and Sub-Systems

    // Run
    run();
}

void GameEngine::initWindow() {
    // Initialize the window
    window = SDL_CreateWindow(
        "Galaga",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        480,
        640,
        SDL_WINDOW_SHOWN
    );
}

void GameEngine::initRenderer() {
    // Intialize the Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

    // Check Renderer
    if (!renderer) { throw std::runtime_error("Failed to create renderer" + std::string(SDL_GetError())); }
    else           { std::cout << "Renderer created sucessfully" << std::endl; }
}

// -------------------------------------------
// Engine
// -------------------------------------------
void GameEngine::run() {
    // Start Timer

    while(isRunning) {
        // Tick Timer

        // Prompt Input System

        // Update ScneManager w/ Input
            // Will have multiple scenes (gameplace, paused, menu, highscores, etc)
            // Depending upon the type of scene, a scene will prompt other managers
                // RenderSystem, CollisionSystem, EntityManager will all be promted by the scene

        // Render the Current Scene

        // Frame Cap -- use timer to force a delay such that this "frame" takes as long as it should
        
    }
}

void GameEngine::shutdown() {
    // Deallocate Managers and Sub-Systems

    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
}