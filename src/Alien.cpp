#include "Sprite.h"
#include "Alien.h"

Alien::Alien(float x, float y, float w, float h, int hp, SDL_Renderer* renderer) 
    : Sprite(x, y, w, h, renderer), health(hp) {
        setSourceRect(188, 154, 8, 9);
    }

void Alien::shoot() {
    std::cout << "Pew" << std::endl;
    missiles.emplace_back(winRect.x + winRect.w / 2, winRect.y, 6, 14, renderer);
}

void Alien::updateMissiles(float dt, SDL_FRect playerWinRect, SDL_FRect alienWinRect) {
    // Update the Missiles Position
    for (auto& missile : missiles) {
        missile.fly(dt, playerWinRect, alienWinRect);
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

void Alien::renderMissiles() {
    for (auto& missile : missiles){
        missile.render();
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Alien Subclasses
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Bee::Bee(float x, float y, float w, float h, int hp, SDL_Renderer* renderer)
    : Alien(x, y, w, h, hp, renderer){
        setSourceRect(188, 154, 8, 9);
}

Butterfly::Butterfly(float x, float y, float w, float h, int hp, SDL_Renderer* renderer)
    : Alien(x, y, w, h, hp, renderer){
        setSourceRect(188, 178, 8, 9);
}

Boss::Boss(float x, float y, float w, float h, int hp, SDL_Renderer* renderer)
    : Alien(x, y, w, h, hp, renderer){
        setSourceRect(185, 104, 14, 14);
}