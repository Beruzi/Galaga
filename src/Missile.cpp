#include "Missile.h"


Missile::Missile(float x, float y, float w, float h, SDL_Renderer* renderer) 
    : Sprite(x, y, w, h, renderer) {
        setSourceRect(381, 107, 3, 7);
}

void Missile::fly(float dt) {
    winRect.y -= 250 * dt;
}