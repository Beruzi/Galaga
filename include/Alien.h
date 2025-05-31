#ifndef ALIEN_H
#define ALIEN_H

#include <Entity.h>


class Alien : public Entity {
public:
    enum class AlienType {
        Bee, 
        Butterfly,
        Boss
    };

private:
    int hp;
    AlienType type;

public:
    Alien();
    Alien(AlienType type, float x, float y, float w, float h);
    ~Alien();
    
    // Alien Functionality
    void move();
    void shoot();


    // Utility
    void setAlienTypeAttributes(AlienType type);

    // 
};
#endif // ALIEN_H