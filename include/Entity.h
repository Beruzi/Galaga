#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <SDL2/SDL.h>


class Entity {
protected:
    SDL_FRect winRect;
    SDL_Rect srcRect;

public:
    // Class Basics
    Entity();
    Entity(int x, int y, int w, int h);
    virtual ~Entity() = 0;

    // Getters & Setters
    const SDL_FRect& getWinRect() const;
    void setWinRect(float x, float y, float w, float h);
    void setWinRect(float x, float y);

    const SDL_Rect& getSrcRect() const;
    void setSrcRect(int x, int y, int w, int h);


    // Entity Fucntionality
    virtual void move(float dx, float dy);

    // Utitilty
    const SDL_Rect toSDL_Rect();
    void printPosition();
    void enforceBounds();
    
};
#endif // ENTITY_H