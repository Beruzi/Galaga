#include "Sprite.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Class Basics
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Sprite::Sprite(){
    winRect = {-1, -1, -1, -1};
    srcRect = {-1, -1, -1, -1};
} 

Sprite::~Sprite() {}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Sprite Renderer
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Sprite::render(SDL_Renderer* renderer, SDL_Texture* spriteSheetTexture) const {
    SDL_Rect intRect = toSDL_Rect();
    SDL_RenderCopy(renderer, spriteSheetTexture, &srcRect, &intRect);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Setters and Getters
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Sprite::setSourceRect(int x, int y, int w, int h) {
    srcRect = {x, y, w, h};
}

void Sprite::setWindowRect(float x, float y, float w, float h) {
    winRect = {x, y, w, h};
}

const SDL_FRect& Sprite::getWindowRect() const {
    return winRect;
}   

const SDL_Rect& Sprite::getSourceRect() const {
    return srcRect;
}

void Sprite::adjustPosition(float dx, float dy) {
    winRect.x += dx;
    winRect.y += dy;
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Utility
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SDL_Rect Sprite::toSDL_Rect() const {
    return SDL_Rect{
        static_cast<int>(winRect.x),
        static_cast<int>(winRect.y),
        static_cast<int>(winRect.w),
        static_cast<int>(winRect.h)
    };
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Other
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



