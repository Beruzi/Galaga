#include "GameEngine.h"

#include <iostream>

// ---------------
// Class Things
// ---------------
GameEngine::GameEngine() : window(nullptr), renderer(nullptr), spriteSheet(nullptr) {}

GameEngine::~GameEngine() {
    shutdown();
}

// -----------------
// Engine Stuff
// -----------------
bool GameEngine::init(char* windowTitle, int width, int height) {
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(
        windowTitle,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );

    if(window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        shutdown();
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if(renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        shutdown();
        return false;
    }

    if(!loadSpriteSheet((char*)"assets/Sprites/SpriteSheet.bmp")) {
        shutdown();
        return false;
    }

    return true;
}

bool GameEngine::loadSpriteSheet(char* texturePath) {
    SDL_Surface* spriteSurface = SDL_LoadBMP(texturePath);
    if(spriteSurface == nullptr) {
        std::cerr << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        return false;
    }

    spriteSheet = SDL_CreateTextureFromSurface(renderer, spriteSurface);
    SDL_FreeSurface(spriteSurface);

    if(spriteSheet == nullptr) {
        std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void GameEngine::shutdown() {
    if(spriteSheet != nullptr) {
        SDL_DestroyTexture(spriteSheet);
        spriteSheet = nullptr;
    }

    if(renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if(window != nullptr) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    SDL_Quit();
}

// ------------------------------
// Get Underlying SDL Resources
// ------------------------------
SDL_Window* GameEngine::getWindow() {
    return window;
}

SDL_Renderer* GameEngine::getRenderer() {
    return renderer;
}

SDL_Texture* GameEngine::getSpriteSheet() {
    return spriteSheet;
}
