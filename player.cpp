#include "player.h"

// ------------------------
// Class Things
// ------------------------
Player::Player() {
    srcRect = {184, 55, 15, 16};
    winRect = {220, 560, 45, 48};
}


// ------------------------
// Player Functionality
// ------------------------
void Player::render(SDL_Renderer* renderer, SDL_Texture* spriteSheet) {
    SDL_RenderCopy(renderer, spriteSheet, &srcRect, &winRect);
}
