#include "InputSystem.h"

InputSystem::InputSystem() {}
InputSystem::~InputSystem() {}

// ----------------------------
// Handling Inputs
// -------------------------------
void InputSystem::processImmediateEvent(SDL_Event event) {
    if (event.key.repeat == 0) {
        std::cout << event.key.keysym.sym << std::endl;
        switch (event.key.keysym.sym) {
        case SDLK_w:
            move();
            break;

        case SDLK_SPACE: 
            //shoot();
            break;
        }
    }
}