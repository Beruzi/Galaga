# Galaga

This is a remake of the 80's arcade game, Galaga. Built using SDL2, I am pursuing this project because I thought it would be a fun way expand upon my C++ knowledge, get some C-style experience in as well (SDL2 is a C-Style API), and have a local game I can play when I'm bored. 


###### Notes



## CODE STRUCTURE
- Game: handles all the the game responsibilities... considered to be the highest power
    - Game loop
    - Forward necessary input to other managers (events)
    - Game state management 

- Game Manager: System level management... name is a little misleading -- doesn't manage the game object per se, but rather provides the utility for the game (system level services/management)
    - SDL Init and cleanup
    - Textures, audios
    - Manaing the window and renderer

- Player : 
    - Stores position, health, lives, etc.
    - Handling animations
- Player Manager 
    - Processing input - sends the data to the player to make changes to its position
    - rendering player and its missiles
    




---------------------------------------------------------------------------------------
Compile Terminal Commands:
- g++ -std=c++17 main.cpp -o prog -I/usr/include/SDL2 -L/usr/lib/x86_64-linux-gnu -lSDL2
- ./prog



---------------------------------------------------------------------------------------
Spritesheet Cordinates (x, y, w, h)
- Default/Upright Player
    - (184, 55, 15, 16)



----------------------------------------------------------------------------------------
Things to add:
- Normalize the diagonal speed... currently diagonal speed is faster than the horizontal and vertical speed.... THIS IS FOR BOTH THE MISSILES AND PLAYER/ALIENS

- Refactor some code...
    - The constructors currently being used for creating any sprite object is a parameterized constructor. It really doesn't make sense to do this... I should just use a default constructor and assign default values of 0 to everything and otherwise I can just call the setWinRect() and setSourceRect() functions.

- NEXT STEPS IS TO ADD COLLISION! This should be fun 


- This is a change to use polymorphism!!! (Using a base class pointer/reference to derived objects)...
    - Specifically during our 2D vector of Aliens... the DS is composed of Alien objects however, each Alien will actually be of a derived type of alien (bee, butterfly, etc). This means that we can treat the aliens generically but still impose specific behavior... for instane the shooting mechanism. The boss type aliens don't shoot missiles, just the ufo gravity picker-upper thing. 

- Move the textureSheet management to the game manager