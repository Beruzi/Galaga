#include <iostream>
#include <SDL2/SDL.h>

#include "../src/Managers/GameManager.h"
#include "Game.h"

// Entry Point
int main(int argc, char *argv[]) {
    GameManager gameManager;
    gameManager.init();

    Game game(gameManager);
    game.run();
    return 0;
}
