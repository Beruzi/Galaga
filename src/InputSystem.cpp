#include "InputSystem.h"

InputSystem::InputSystem() {}
InputSystem::InputSystem(Player* player) : player(player) {}
InputSystem::~InputSystem() {}

// ----------------------------
// Handling Inputs
// -------------------------------
void InputSystem::handlePlayerEvent(float dt) {
    const Uint8* keyState = SDL_GetKeyboardState(NULL);

    if (keyState[SDL_SCANCODE_W]) {
        player->move(0, -200 * dt);
    }
    if (keyState[SDL_SCANCODE_A]) {
        player->move(-200 * dt, 0);
    }
    if (keyState[SDL_SCANCODE_S]) {
        player->move(0, 200 * dt);
    }
    if (keyState[SDL_SCANCODE_D]) {
        player->move(200 * dt, 0);
    }

    // Check Bounds
    //player->enforceBounds();
}