#include "AlienManager.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Class Basics
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AlienManager::AlienManager(GameManager& gm) 
    : gameManager(gm) {}

AlienManager::~AlienManager() {}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Managing Aliens
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void AlienManager::initAliens(int rows, int cols) {
    aliens.resize(rows);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            Alien alien; 
            alien.setWindowRect(j * 40.0f, i * 40.0f, 30.0f, 30.0f); // Adjust size/spacing
            aliens[i].push_back(alien);
        }
    }
}

void AlienManager::moveAliens(float dt) {
    for (auto& row : aliens) {
        for (auto& alien : row) {
            // Gotta implement how they move 
            alien.adjustPosition(0, 0);
        }
    }
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Managing Missiles
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void AlienManager::shoot(const Alien& alien) {
    missiles.emplace_back(
        alien.getWindowRect().x + (alien.getWindowRect().w / 2), 
        alien.getWindowRect().y + alien.getWindowRect().h,       
        6, 14, 
        gameManager.getRenderer()
    );
}

void AlienManager::updateMissiles(float dt) {
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

void AlienManager::renderMissiles() {
    for (const auto& missile : missiles) {
        missile.render(gameManager.getRenderer(), gameManager.getSpriteSheet());
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Update
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void AlienManager::update(float dt) {
    moveAliens(dt);
    updateMissiles(dt);   
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Render
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void AlienManager::render() {
    for (const auto& row : aliens) {
        for (const auto& alien : row) {
            alien.render(gameManager.getRenderer(), gameManager.getSpriteSheet());
        }
    }
    renderMissiles();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Utility
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
