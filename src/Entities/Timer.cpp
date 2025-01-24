#include "Timer.h"

Timer::Timer() : previousTicks(0), deltaTime(0.0f) {}

void Timer::tick() {
    Uint32 currentTicks = SDL_GetTicks(); // Get the current tick count
    deltaTime = (currentTicks - previousTicks) / 1000.0f; // Calculate delta time in seconds
    previousTicks = currentTicks; // Update previous ticks for the next frame
}

float Timer::getDeltaTime() const {
    return deltaTime;
}
