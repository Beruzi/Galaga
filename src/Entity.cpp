#include "Entity.h"

// -------------------------------------------
// Class Basics
// -------------------------------------------
Entity::Entity() : winRect({-1, -1, -1, -1}), srcRect({-1, -1, -1, -1}) {}

Entity::Entity(int srcX, int srcY, int w, int h) 
    : winRect({0, 0, 0, 0}), srcRect({srcX, srcY, w, h}) {}

Entity::Entity(int srcX, int srcY, float winX, float winY, int w, int h) 
    : winRect({winX, winY, float(w), float(h)}), srcRect({srcX, srcY, w, h}) {}
    
Entity::~Entity() {}

// -------------------------------------------
// Getters and Setters
// -------------------------------------------
const SDL_FRect &Entity::getWinRect() const { return winRect; }
void Entity::setWinRect(float x, float y, float w, float h) { winRect = {x, y, w, h}; }

const SDL_Rect &Entity::getSrcRect() const { return srcRect; }
void Entity::setSrcRect(int x, int y, int w, int h) { srcRect = {x, y, w, h}; }

// -------------------------------------------
// Entity Functionality
// -------------------------------------------
void Entity::move(float dx, float dy)
{
    winRect.x += dx;
    winRect.y += dy;
}

// -------------------------------------------
// Utility
// -------------------------------------------
const SDL_Rect Entity::toSDL_Rect()
{
    return SDL_Rect{
        static_cast<int>(winRect.x),
        static_cast<int>(winRect.y),
        static_cast<int>(winRect.w),
        static_cast<int>(winRect.h)};
}

void Entity::printPosition()
{
    auto temp = toSDL_Rect();
    printf("x: %i, y: %i, w: %i, h: %i", temp.x, temp.y, temp.w, temp.h);
}
