# Galaga
In Progress Notes:
- GameEngine Event Handling (directly inside event loop)
    - Currently only caring about the SDL_QUIT event....
        - Look into SDL_WindowEvent and SDL_DisplayEvent

- Gameplay Event handling (forwarded to input system)


- Eventually migrate constants to something cleaner
    - Window width and height
    - source rectangles for Sprites
    - Starting location for a new player ship
    - the 5p border for the entire window
    - 

- Double Fire Power
    - When saving a Galaga Ship, we basically have two intances of the player..
        - Can either create a new instance of the player entity (change members upon instantiation)
        - Define the copy assignment operator or copy constructor (a 1 to 1 copy to simply double up on the player entities)    