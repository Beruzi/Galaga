#include <iostream>
#include <SDL2/SDL.h>

#include "sprite.h"

/**
 * @brief Handles all things player. 
*/
class Player : public Sprite {
public:
    // Constructor
    Player(float x, float y, float w, float h, SDL_Renderer* renderer) 
        : Sprite(x, y, w, h, renderer) {
        
        // Set the Source Rectangle to the default/upright player sprite
        setSourceRect(184, 55, 15, 16);
    }
public:
    
    
    /**
     * @brief Handles the movement inputs (WASD)... this uses the keyboard state rather than the event'
     * to bypass the 'repeated key delay' that the OS imposes
     */
    void processMovement(float dt) {
        const Uint8* keyState = SDL_GetKeyboardState(NULL);
        if (keyState[SDL_SCANCODE_W]) {
            rect.y -= (200 * dt);
        }
        if (keyState[SDL_SCANCODE_A]) {
            rect.x -= (200 * dt);
        }
        if (keyState[SDL_SCANCODE_S]) {
            rect.y += (200 * dt);
        }
        if (keyState[SDL_SCANCODE_D]) {
            rect.x += (200* dt);
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
