#include "Sprite.h"
#include "Player.h"

Player::Player(float x, float y, float w, float h, SDL_Renderer* renderer)
    : Sprite(x, y, w, h, renderer) {
    // Set the Source Rectangle to the default/upright player sprite
    setSourceRect(184, 55, 15, 16);
}

void Player::handleImmediateInput(SDL_Event& event) {
    if (event.type ==  SDL_KEYDOWN && event.key.repeat == 0) {
        switch (event.key.keysym.sym) {
            case SDLK_SPACE: // Fire a missle
                shoot();
                break;
        }
    }
}

void Player::handleContinousInput(float dt) {
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

void Player::enforceBounds() {
    // Adds a 5 pixel border padding
    if (rect.x < 5) rect.x = 5;
    if (rect.y < 5) rect.y = 5;
    if (rect.x + rect.w > 480 - 5) rect.x = 480 - 5 - rect.w;
    if (rect.y + rect.h > 640 - 5) rect.y = 640 - 5 - rect.h;
}

void Player::shoot() {
    std::cout << "Pew" << std::endl;
    missiles.emplace_back(rect.x + rect.w / 2, rect.y, 6, 14, renderer);
}

void Player::updateMissiles(float dt) {
    for (auto& missile : missiles){
        missile.fly(dt);
    }
}

void Player::renderMissiles() {
    for (auto& missile : missiles){
        missile.render();
    }
}


