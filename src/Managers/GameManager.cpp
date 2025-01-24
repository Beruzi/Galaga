#include "GameManager.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Class Basics
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
GameManager::GameManager() : renderer(nullptr), window(nullptr), spriteSheetTexture(nullptr) {}

GameManager::~GameManager() {
    cleanUpSDL();
}

void GameManager::cleanUpSDL() {
    if (spriteSheetTexture) SDL_DestroyTexture(spriteSheetTexture);
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// SDL
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void GameManager::init() {
    // Intialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Quit();
        throw std::runtime_error("SDL_Init Failed" + std::string(SDL_GetError()));
    }
    else {
        std::cout << "SDL Ready to go" << std::endl;
    }

    try {
        initWindow();
        initRenderer();
        loadSpriteSheet("assets/Sprites/SpriteSheet.bmp");
    } catch (...) {
        SDL_Quit();
        throw;
    }
}

void GameManager::initWindow() {
    // Initialize the window
    window = SDL_CreateWindow(
        "Galaga",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        480,
        640,
        SDL_WINDOW_SHOWN
    );

    // Check Window
    if (!window) {
        throw std::runtime_error("Failed to create window" + std::string(SDL_GetError()));
    }
    else {
        std::cout << "Window created sucessfully" << std::endl;
    }
}

void GameManager::initRenderer() {
    // Intialize the Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

    // Check Renderer
    if (!renderer) {
        throw std::runtime_error("Failed to create renderer" + std::string(SDL_GetError()));
    }
    else {
        std::cout << "Renderer created sucessfully" << std::endl;
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Sprite Sheet
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void GameManager::loadSpriteSheet(const char* spriteSheetPath) {
    // Load the sprite sheet as a surface
    SDL_Surface* surface = SDL_LoadBMP(spriteSheetPath);

    // Check if surface was loaded
    if (!surface) {
        throw std::runtime_error("Failed to load sprite sheet: " + std::string(SDL_GetError()));
    }

    // Convert the surface to a texture
    spriteSheetTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    
    // Check if texture was loaded propery
    if (!spriteSheetTexture) {
        throw std::runtime_error("Failed to create texture: " + std::string(SDL_GetError()));
    }
}

SDL_Texture* GameManager::getSpriteSheet() const {
    return spriteSheetTexture;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Utility
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SDL_Renderer* GameManager::getRenderer() const {
    return renderer;
}