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



};


// 184, 55
// 15w x 16h