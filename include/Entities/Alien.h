#ifndef ALIEN_H
#define ALIEN_H 

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "GameManager.h"
#include "Sprite.h"
#include "Missile.h"


class Alien : public Sprite {
public:
    Alien();
};


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Alien Subclasses
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class Bee : public Alien {
public:
    Bee();
};

class Butterfly : public Alien {
public:
    Butterfly();
};

class Boss : public Alien {
public:
    Boss();
};

#endif