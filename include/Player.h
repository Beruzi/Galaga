#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include "Sprite.h"

class Player : public Sprite {
public:
    // Class Basics
    Player();

    // Utility 
    void enforceBounds();
};

#endif 