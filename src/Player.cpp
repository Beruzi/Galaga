#include "Sprite.h"
#include "Player.h"

Player::Player(float x, float y, float w, float h, SDL_Renderer* renderer)
    : Sprite(x, y, w, h, renderer) {
    // Set the Source Rectangle to the default/upright player sprite
    setSourceRect(184, 55, 15, 16);
}


void Player::processMovement(float dt) {
    const Uint8* keyState = SDL_GetKeyboardState(NULL);
    if (keyState[SDL_SCANCODE_W]) {
        rect.y -= (200 * dt);
    }
    if (keyState[SDL_SCANCODE_A]) {
        rect.x -= (200 * dt);
    }
    if (keyState[SDL_SCANCODE_S]) {
        rect.y += (200 * dt);
    }
    if (keyState[SDL_SCANCODE_D]) {
        rect.x += (200* dt);
    }

    // Check Bounds
    enforceBounds();
}

void Player::shoot() {
    std::cout << "Pew" << std::endl;
}

void Player::enforceBounds() {
    // Adds a 5 pixel border padding
    if (rect.x < 5) rect.x = 5;
    if (rect.y < 5) rect.y = 5;
    if (rect.x + rect.w > 480 - 5) rect.x = 480 - 5 - rect.w;
    if (rect.y + rect.h > 640 - 5) rect.y = 640 - 5 - rect.h;
}