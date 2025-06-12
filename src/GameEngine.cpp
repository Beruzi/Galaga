#include "GameEngine.h"


// -------------------------------------------
// Class Basics
// -------------------------------------------
GameEngine::GameEngine() 
    : window(nullptr), renderer(nullptr), isRunning(false), player(nullptr) {}

GameEngine::~GameEngine() {
    shutdown();
}

// -------------------------------------------
// Intialize SDL Resources
// -------------------------------------------
void GameEngine::init() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Quit();
        throw std::runtime_error("SDL_Init Failed" + std::string(SDL_GetError()));
    }
    else {
        std::cout << "SDL Ready to go" << std::endl;
    }

    // Initialize SDL Resources
    isRunning = true;
    initWindow();
    initRenderer();

    
    // Initialize Subsystems and Assets
    renderSystem = new RenderSystem(renderer);
    timer = new Timer();
    inputSystem = new InputSystem(player);
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
    if (!window) { throw std::runtime_error("Failed to Create Window" + std::string(SDL_GetError())); }
    else { }
}

void GameEngine::initRenderer() {
    // Intialize the Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

    // Check Renderer
    if (!renderer) { throw std::runtime_error("Failed to create renderer" + std::string(SDL_GetError())); }
    else { std::cout << "Renderer created sucessfully" << std::endl;}
}

// -------------------------------------------
// Engine
// -------------------------------------------
void GameEngine::run() {
    while(isRunning) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            switch (event.type) { // Game Level Events
                case SDL_QUIT:
                    isRunning = false;
                    break;
                case SDL_KEYDOWN:
                    // TODO: check for "esc" or perhaps "p" for pause
                    break;
                case SDL_MOUSEMOTION:
                    // TODO: Check for mouse motion?
                    break;
            }             
        }
        float dt = timer->tick();
        /* TODO: Through the SceneManager, invoke all subsystems according to the specific scene:
                    - Menu Scene
                    - Highschore Scene
                    - Gameplay Scene
                        - Pause
                Depending on the scene above, subsystems will perform differently with certain inputs
        */

        inputSystem->handlePlayerEvent(dt);


        // RENDERING SHIT
        SDL_RenderClear(renderer);
        renderSystem->render(player);
        SDL_RenderPresent(renderer);

        // TODO: Frame Cap -- use timer to force a delay such that this "frame" takes as long as it should
    }
    shutdown();
}

void GameEngine::shutdown() {
    // TODO Free Managers and Sub-Systems

    // Free SDL Resources
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
}