#include "EntityManager.h"

EntityManager::EntityManager() : entityFactory(nullptr), player(nullptr), aliens({}) {
    entityFactory = new EntityFactory();
}

EntityManager::~EntityManager() {}



// Entity Creation
void EntityManager::addPlayer() {
    player = entityFactory->createPlayer(250, 100);
}

void EntityManager::addAlien() {
    aliens.emplace_back(entityFactory->createAlien(Alien::AlienType::Bee, 300, 300));
}


