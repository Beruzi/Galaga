#include "Missile.h"


Missile::Missile() {
    setSourceRect(381, 107, 3, 7);
}

void Missile::fly(float dt) {
    winRect.y -= 250 * dt;
}

void Missile::fly(float dt, const SDL_FRect& playerWinRect, const SDL_FRect& alienWinRect) {
    // Calculate the components of the direction the missile needs to move in
    float dx = playerWinRect.x - alienWinRect.x;
    float dy = playerWinRect.y - alienWinRect.y;


    int speed = 250;
    // Adjust the position of the missile
    winRect.x += dx * speed * dt;
    winRect.y += dy * speed * dt;

}

bool Missile::isOffScreen() {
    return (winRect.y < 0);
}