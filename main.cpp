#include <SDL2/SDL.h>

#include "GameEngine.h"
#include "player.h"

int main() {
    GameEngine engine;
    if(!engine.init((char*)"Galaga", 480, 640)) {
        return 1;
    }

    // Init Player Object
    Player player;

    bool running = true;
    SDL_Event event;
    while(running) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(engine.getRenderer(), 0, 0, 0, 255);
        SDL_RenderClear(engine.getRenderer());

        // Render the Player's sprite
        player.render(engine.getRenderer(), engine.getSpriteSheet());
        SDL_RenderPresent(engine.getRenderer());
    }

    return 0;
}
