#include "Sprite.h"

// Initialize static member
SDL_Texture* Sprite::spriteSheetTexture = nullptr;
int Sprite::spriteCount = 0;

Sprite::Sprite(float x, float y, float w, float h, SDL_Renderer* renderer)
    : renderer(renderer) {
    winRect = {x, y, w, h};
    srcRect = {0, 0, static_cast<int>(w), static_cast<int>(h)};
}

Sprite::~Sprite() {
    --spriteCount;
    if (spriteCount == 0 && spriteSheetTexture) {
        SDL_DestroyTexture(spriteSheetTexture);
        spriteSheetTexture = nullptr; 
    }
}

void Sprite::LoadSpriteSheet(SDL_Renderer* renderer, const char* spriteSheetPath) {
    // Load the sprite sheet as a surface
    SDL_Surface* surface = SDL_LoadBMP(spriteSheetPath);
    if (!surface) {
        std::cerr << "Failed to load sprite sheet: " << SDL_GetError() << std::endl;
        exit(1);
    }

    // Convert the surface to a texture
    spriteSheetTexture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!spriteSheetTexture) {
        std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
        exit(1);
    }

    // Free the surface
    SDL_FreeSurface(surface);
}

void Sprite::setSourceRect(int x, int y, int w, int h) {
    srcRect = {x, y, w, h};
}

void Sprite::setWindRect(float x, float y, float w, float h) {
    winRect = {x, y, w, h};
}

const SDL_FRect& Sprite::getWindRect() {
    return winRect;
}   


void Sprite::render() {
    SDL_Rect intRect = toSDL_Rect();
    SDL_RenderCopy(renderer, spriteSheetTexture, &srcRect, &intRect);
}

SDL_Rect Sprite::toSDL_Rect() const {
    return SDL_Rect{
        static_cast<int>(winRect.x),
        static_cast<int>(winRect.y),
        static_cast<int>(winRect.w),
        static_cast<int>(winRect.h)
    };
}


void Sprite::print() {
    std::cout << "Position of Sprite" << std::endl;
}
