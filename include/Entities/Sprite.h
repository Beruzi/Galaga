#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <SDL2/SDL.h>

/**
 * @brief Abstract Class to be inherited by any sprite related object (player, enemy, missle, etc.)
 * @details Contains members winRect and srcRect that act as the bounds (location and dimensions) for sprites
 * and the bounds for where to find the sprite on the spritesheet.
 */
class Sprite {
protected:
    SDL_FRect winRect;      
    SDL_Rect srcRect;   

public:
    // Class Basics
    Sprite();
    virtual ~Sprite();

    // Sprite Rendering
    void render(SDL_Renderer* renderer, SDL_Texture* spriteSheetTexture) const;
    
    // Getters and Setters
    void setSourceRect(int x, int y, int w, int h);
    void setWindowRect(float x, float y, float w, float h);
    const SDL_FRect& getWindowRect() const;
    const SDL_Rect& getSourceRect() const;

    void adjustPosition(float dx, float dy);

    // Utiltiy
    SDL_Rect toSDL_Rect() const;

    // Other
};

#endif // SPRITE_H
