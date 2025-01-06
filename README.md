# Galaga

This is a remake of the 80's arcade game, Galaga. Built using SDL2, I am pursuing this project because I thought it would be a fun way expand upon my C++ knowledge, get some C-style experience in as well (SDL2 is a C-Style API), and have a local game I can play when I'm bored. 


###### Notes
I'll be taking some general notes for myself in this space, so just ignore. Towards the end of the project I'll post the actual set of notes I've been taking alongside development. This will cover some things I'ver learned about using SDL2, general game development, CPP stuff, and more.  





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
- Normalize the diagonal speed... currently diagonal speed is faster than the horizontal and vertical speed

- Refactor the file structure 
    - Create seperate source and header files... compiling time is starting to piss me off
    - Create the proper build dir
    - Dabble in Cmake stuff
    - update the .gitignore file as needed
