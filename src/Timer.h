#include <iostream>
#include <SDL2/SDL.h>

/**
 * @brief Object used handle/navigate tickspeed. 
 * @note deltaTime is the time elapsed in seconds
 */
class Timer {
private:
    Uint32 previousTicks;
    float deltaTime;

public:
    // Default Constructor
    Timer() : previousTicks(0), deltaTime(0) {}

    void Tick() {
        Uint32 currentTicks = SDL_GetTicks();
        deltaTime = (currentTicks - previousTicks) / 1000.0f;
        previousTicks = currentTicks;
    }

    float getDeltaTime() {
        return deltaTime;
    }    
};
