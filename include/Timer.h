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
    /**
     * @brief Constructs the Timer object and initializes timing values.
     */
    Timer();

    /**
     * @brief Updates the timer and calculates the delta time for the current frame.
     */
    void Tick();

    /**
     * @brief Retrieves the time elapsed (delta time) since the last frame.
     * @return The delta time in seconds.
     */
    float getDeltaTime() const;
};

#endif
