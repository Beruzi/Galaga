# Galaga

This is a remake of the 80's arcade game, Galaga. Built using SDL2, I am pursuing this project because I thought it would be a fun way expand upon my C++ knowledge, get some C-style experience in as well (SDL2 is a C-Style API), and have a local game I can play when I'm bored. 


###### Notes
I'll be taking some general notes for myself in this space, so just ignore. Towards the end of the project I'll post my journal of notes I'll be taking alongside of development. 





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
- Constants File 
    - Will handle some constants like the sprite sheet path or width + height of the sprites

- Change how keyboard event handling works... at the moment I can only handle one button press at a time in a sequential order (duh the event queue).... this means however that it is impossible to move diagonal or fire and move at the same time.
