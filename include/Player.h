#ifndef PLAYER_H
#define PLAYER_H

#include <Entity.h>

class Player : public Entity {
private:
    int hp;
    // Some ADT for missles

public:
    Player();
    ~Player();
    
    // Player Functionality
    void move(float dx, float dy) override;
    void shoot();

    // Player Utility
    void enforceBounds();
    

};
#endif // PLAYER_H