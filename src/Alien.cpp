#include "Alien.h" 

Alien::Alien() {}
Alien::Alien(AlienType type, float x, float y, float w, float h) : type(type), hp(0) {
    setAlienTypeAttributes(type);
    setWinRect(x, y, w, h);
}
Alien::~Alien() {}


// Alien Functionality
void Alien::move() {
    std::cout << "ALIEN MOVE" << std::endl;
}


// Utiltiy
void Alien::setAlienTypeAttributes(AlienType type) {
    switch (type) {
        case AlienType::Bee:
            setSrcRect(162, 178, 16, 16);
            hp = 1;
            break;
        case AlienType::Butterfly:
            setSrcRect(162, 154, 16, 16);
            hp = 1;
            break;
        case AlienType::Boss:
            setSrcRect(161, 103, 16, 16);
            hp = 2;
            break;
    }
}