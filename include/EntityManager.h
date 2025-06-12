#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <iostream>
#include <vector>
#include "Entity.h" //Polymorphic behavior
#include "EntityFactory.h"

class EntityManager {
private:
    EntityFactory* entityFactory;
    Entity* player; //TODO? Change to a vector to account for multiple Player instances
    std::vector<Entity*> aliens;

public:
    EntityManager();
    ~EntityManager();

    // Entity Creation
    void addPlayer();
    void addAlien();

    // Entity 

}; 
#endif // ENTITYMANAGER_H