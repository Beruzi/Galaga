#include <iostream>
#include <SDL2/SDL.h>


#include "game.h"

/*
    Entry Point
*/
int main(int argc, char *argv[]) {
    Game Galaga;
    Galaga.run();
    SDL_Quit();
    return 0;
}
