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
        winRect.y -= (200 * dt);
    }
    if (keyState[SDL_SCANCODE_A]) {
        winRect.x -= (200 * dt);
    }
    if (keyState[SDL_SCANCODE_S]) {
        winRect.y += (200 * dt);
    }
    if (keyState[SDL_SCANCODE_D]) {
        winRect.x += (200* dt);
    }

    // Check Bounds
    enforceBounds();
}

void Player::enforceBounds() {
    // Adds a 5 pixel border padding
    if (winRect.x < 5) winRect.x = 5;
    if (winRect.y < 5) winRect.y = 5;
    if (winRect.x + winRect.w > 480 - 5) winRect.x = 480 - 5 - winRect.w;
    if (winRect.y + winRect.h > 640 - 5) winRect.y = 640 - 5 - winRect.h;
}

void Player::shoot() {
    std::cout << "Pew" << std::endl;
    missiles.emplace_back(winRect.x + winRect.w / 2, winRect.y, 6, 14, renderer);
}

void Player::updateMissiles(float dt) {
    // Update the Missiles Position
    for (auto& missile : missiles) {
        missile.fly(dt);
    }

    // Erase any Missiles that are off screen using the remove-erase technique
    missiles.erase(
        std::remove_if(
            missiles.begin(), 
            missiles.end(),
            std::mem_fn(&Missile::isOffScreen)
        ),
        missiles.end()
    );
    std::cout << missiles.size() << std::endl;
}

void Player::renderMissiles() {
    for (auto& missile : missiles){
        missile.render();
    }
}


