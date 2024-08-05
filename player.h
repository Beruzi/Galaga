#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

class Player {
private:
    // Relevant SDL resources
    SDL_Rect srcRect;
    SDL_Rect winRect;

public:
    // Class Things
    Player();

    // Render
    void render(SDL_Renderer* renderer, SDL_Texture* spriteSheet);
};

#endif // PLAYER_H
