#ifndef ENTITYFACOTRY_H
#define ENTITYFACTORY_H

#include <iostream>

#include <Entity.h>
#include <Player.h>
#include <Alien.h>



class EntityFactory {
private:
public:
    EntityFactory();
    ~EntityFactory();

    Entity* createPlayer(float x, float y);
    Entity* createAlien(Alien::AlienType type, float x, float y);
    //void createMissile();
}; 
#endif // ENTITYFACTORY_H