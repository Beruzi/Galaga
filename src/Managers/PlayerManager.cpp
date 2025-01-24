#include "PlayerManager.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Class Basics
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
PlayerManager::PlayerManager(GameManager& gm) 
    : gameManager(gm) {

}

PlayerManager::~PlayerManager() {
    if (player) {
        delete player;
        player = nullptr;
    }
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Managing Player
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void PlayerManager::initPlayer() {
    player = new Player();
}

void PlayerManager::handleImmediateInput(SDL_Event& event) {
    if (event.type ==  SDL_KEYDOWN && event.key.repeat == 0) {
            switch (event.key.keysym.sym) {
            case SDLK_SPACE: 
                shoot();
                break;
        }
    }
}

void PlayerManager::handleContinousInput(float dt) {
    const Uint8* keyState = SDL_GetKeyboardState(NULL);
    if (keyState[SDL_SCANCODE_W]) {
        player->adjustPosition(0, -200 * dt);
    }
    if (keyState[SDL_SCANCODE_A]) {
        player->adjustPosition(-200 * dt, 0);
    }
    if (keyState[SDL_SCANCODE_S]) {
        player->adjustPosition(0, 200 * dt);
    }
    if (keyState[SDL_SCANCODE_D]) {
        player->adjustPosition(200 * dt, 0);
    }

    // Check Bounds
    player->enforceBounds();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Managing Missiles
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void PlayerManager::shoot() {
    if (!player) return;

    // Create a new missile at the player's current position
    missiles.emplace_back(
        player->getWindowRect().x + (player->getWindowRect().w / 2), // Missile starts at the player's center
        player->getWindowRect().y,
        6, 14, // Missile dimensions
        gameManager.getRenderer() // Pass renderer
    );
}

void PlayerManager::updateMissiles(float dt) {
    // Update all missiles
    for (auto& missile : missiles) {
        missile.fly(dt);
    }

    // Remove off-screen missiles
    missiles.erase(
        std::remove_if(
            missiles.begin(), 
            missiles.end(),
            std::mem_fn(&Missile::isOffScreen)
        ),
        missiles.end()
    );
}

void PlayerManager::renderMissiles() {
    for (const auto& missile : missiles) {
        missile.render(gameManager.getRenderer(), gameManager.getSpriteSheet());
    }
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Update
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void PlayerManager::update(float dt) {
    handleContinousInput(dt);
    updateMissiles(dt);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Rendering
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void PlayerManager::render() {
    player->render(gameManager.getRenderer(), gameManager.getSpriteSheet());
    renderMissiles();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Utility
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~