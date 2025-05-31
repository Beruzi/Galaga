#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include <iostream>
#include <SDL2/SDL.h>

#include "Player.h"

class InputSystem
{
private:
    // Subsystems to Forward Inputs to
        //EntityManager* entityManager;
            Player* player;
        //SceneManager* sceneManager;
        //audioSystem* audioSystem;
public:
    InputSystem();
    InputSystem(Player* player);
    ~InputSystem();

    // Handle Game Events
    // void handleGameEvent(SDL_Event) maybe make this a const SDL_Event*?
    void handlePlayerEvent(float dt); // keystrokes, mouse

};
#endif // INPUTSYSTEM_H