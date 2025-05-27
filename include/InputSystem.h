#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include <iostream>
#include <SDL2/SDL.h>

class InputSystem
{
private:
public:
    InputSystem();
    ~InputSystem();

    // Handle
    void processImmediateEvent(SDL_Event event);

};
#endif // INPUTSYSTEM_H