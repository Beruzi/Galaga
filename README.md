# Galaga
In Progress Notes:
- GameEngine Event Handling (directly inside event loop)
    - Currently only caring about the SDL_QUIT event....
        - Look into SDL_WindowEvent and SDL_DisplayEvent

- Gameplay Event handling (forwarded to input system)

- Constructors Member Init List for Entity is a little odd right now... don't really know if I want to or should i even be initializing the posRect;