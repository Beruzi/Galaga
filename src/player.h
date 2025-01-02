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
public:
    /**
     * @brief Handling input IMMEDIATELY -- is called within the event loop 
     */
    void handleImmediateInput(const SDL_Event& event) {
        if (event.type == SDL_KEYDOWN && event.key.repeat == 0) { 
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

        // Check Bounds
        enforceBounds();
    }
    
    /**
     * Handling any CONTINOUS input -- called outside the event loop
     */
    void handleContinousInput(const SDL_Event& event) {
        const Uint8* keyState = SDL_GetKeyboardState(NULL);
        if (keyState[SDL_SCANCODE_W]) {
            rect.y -= 5;
        }
        if (keyState[SDL_SCANCODE_A]) {
            rect.x -= 5;
        }
        if (keyState[SDL_SCANCODE_S]) {
            rect.y += 5;
        }
        if (keyState[SDL_SCANCODE_D]) {
            rect.x += 5;
        }

        // Check Bounds
        enforceBounds();
    }

    /**
     * @brief player fires a shot
     */
    void shoot() {
        std::cout << "Pew" << std::endl;
    }


public:
    void enforceBounds() {
        // Currently '5' acts as my number for the border padding... to remove border just set every '5' to a '0'
        if (rect.x < 5) rect.x = 5;
        if (rect.y < 5) rect.y = 5;
        if (rect.x + rect.w > 480 - 5) rect.x = 480 - 5 - rect.w;
        if (rect.y + rect.h > 640 - 5) rect.y = 640 - 5 - rect.h;
    }
};
