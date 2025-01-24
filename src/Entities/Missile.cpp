#include "Missile.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Class Basics
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Missile::Missile(float x, float y, int speed) 
    : speed(speed) {
    setWindowRect(x, y, 3, 7);
    setSourceRect(381, 107, 3, 7);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Missile Movement
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Missile::fly(float dt) {
    winRect.y -= speed * dt; // Move vertically upward
}


void Missile::fly(float dt, const SDL_FRect& target) {
    // Find the direction
    float dx = target.x - winRect.x;
    float dy = target.y - winRect.y;

    // Normalize the direction vector
    float magnitude = std::sqrt(dx * dx + dy * dy);
    if (magnitude == 0) return;

    dx /= magnitude;
    dy /= magnitude;

    // Adjust the position of the missile
    winRect.x += dx * speed * dt;
    winRect.y += dy * speed * dt;
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Utility
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool Missile::isOffScreen() const {
    return (winRect.y < 0 || winRect.y > 640 || winRect.x < 0 || winRect.x > 480);
}

