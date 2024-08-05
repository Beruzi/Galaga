#include <SDL2/SDL.h>
#include <iostream>

#include "GameEngine.h"
#include "player.h"

int main() {
    GameEngine engine;
    if(!engine.init((char*)"Galaga", 480, 640)) {
        return 1;
    }

    // Init Player Object
    Player player;
    int playerSpeed = 1;

    bool running = true;
    SDL_Event event;
    while(running) {
        
        // Event Driven 
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Continous Polling of state -- for smooth player movement
        int* numKeys;
        const Uint8* keyboardState = SDL_GetKeyboardState(numKeys);
        if (keyboardState[SDL_SCANCODE_W]) {
            player.move(0, -playerSpeed);
        }
        if (keyboardState[SDL_SCANCODE_A]) {
            player.move(-playerSpeed, 0);
        }
        if (keyboardState[SDL_SCANCODE_S]) {
            player.move(0, playerSpeed);
        }
        if (keyboardState[SDL_SCANCODE_D]) {
            player.move(playerSpeed, 0);
        }


        SDL_SetRenderDrawColor(engine.getRenderer(), 0, 0, 0, 255);
        SDL_RenderClear(engine.getRenderer());

        // Render the Player's sprite
        player.render(engine.getRenderer(), engine.getSpriteSheet());
        SDL_RenderPresent(engine.getRenderer());
    }

    return 0;
}
