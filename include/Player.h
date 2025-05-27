#ifndef PLAYER_H
#define PLAYER_H

#include <Entity.h>

class Player : public Entity {
private:
    int lives;
    // Some ADT for missles

public:
    Player();
    ~Player();
    
    // Player Events
    void shoot();

    
    

};
#endif // PLAYER_H