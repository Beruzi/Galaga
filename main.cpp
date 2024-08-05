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
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                running = false;
            }
            else if(event.type == SDL_KEYDOWN) {
                switch(event.key.keysym.sym) {
                    case SDLK_w:
                        player.move(0, -playerSpeed);
                        break;
                    case SDLK_a:
                        player.move(-playerSpeed, 0);
                        break;
                    case SDLK_s:
                        player.move(0, playerSpeed);
                        break;
                    case SDLK_d:
                        player.move(playerSpeed, 0);
                        break;
                    case SDLK_SPACE:
                        std::cout << "MISSILE!" << std::endl;
                        break;
                    default:
                        break;
                }
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
