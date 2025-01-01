#include <iostream>
#include <SDL2/SDL.h>
#include "sprite.h"

/**
 * @brief Handles all things player. 
*/
class Player : public Sprite {
public:
    // Constructor
    Player(int x, int y, int w, int h, SDL_Renderer* renderer) 
        : Sprite(x, y, w, h, renderer) {
        
        // Set the Source Rectangle to the default/upright player sprite
        setSourceRect(184, 55, 15, 16);
    }

    /**
     * @brief Handling all types of input for the player... moving and shooting
     */
    void handleInput(const SDL_Event& event) {
        if (event.type == SDL_KEYDOWN){
            switch (event.key.keysym.sym) {
                case SDLK_w: 
                    rect.y -= 5; 
                    break;
                case SDLK_a:
                    rect.x -= 5; 
                    break;
                case SDLK_s:
                    rect.y += 5; 
                    break;
                case SDLK_d:
                    rect.x += 5; 
                    break;
                case SDLK_SPACE:
                    shoot();
                    break;
            }
        }
    }

    /**
     * @brief player fires a shot
     */
    void shoot() {
        std::cout << "Pew" << std::endl;
    }
};
