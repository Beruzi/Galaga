#ifndef TIMER_H
#define TIMER_H

#include <SDL2/SDL.h>

/**
 * @brief A utility class for handling frame timing and delta time calculations.
 * @note Delta time is the time elapsed between frames, measured in seconds.
 */
class Timer {
private:
    Uint32 previousTicks; 
    float deltaTime;      

public:
    Timer();
    ~Timer();

    float tick();
    float getDeltaTime() const;
};

#endif
