#include "Sprite.h"
#include "Alien.h"

Alien::Alien() {}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Alien Subclasses
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Bee::Bee() {
    setSourceRect(188, 154, 8, 9);
}

Butterfly::Butterfly(){
    setSourceRect(188, 178, 8, 9);
}

Boss::Boss(){
    setSourceRect(185, 104, 14, 14);
}