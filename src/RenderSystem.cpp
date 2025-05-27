#include "RenderSystem.h"

// -------------------------------------------
// Class Basics
// -------------------------------------------
RenderSystem::RenderSystem() : renderer(nullptr), spriteSheetTexture(nullptr) {}
RenderSystem::RenderSystem(SDL_Renderer* renderer) : renderer(renderer) {
    loadSpriteSheet();
}
RenderSystem::~RenderSystem() {}

// -------------------------------------------
// Load the Sprite Sheet Texture
// -------------------------------------------
void RenderSystem::loadSpriteSheet() {
    
    // Load the sprite sheet as a surface
    SDL_Surface* surface = SDL_LoadBMP("assets/Sprites/SpriteSheet.bmp");

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
   
   std::cout << "Sprite Sheet Loaded Succefully" << std::endl;

}

// -------------------------------------------
// Rendering
// -------------------------------------------
void RenderSystem::sceneRender() {
    // Call render() on all relevant entities in the scene
    std::cout << "SCENE RENDER FIRES" << std::endl;
}

void RenderSystem::render(const Entity* entity) {
    SDL_RenderClear(renderer);
    if (SDL_RenderCopyF(renderer, spriteSheetTexture, &entity->getSrcRect(), &entity->getWinRect()) != 0) {
        throw std::runtime_error("Failed to Render: " + std::string(SDL_GetError()));
    }
    SDL_RenderPresent(renderer);
}

