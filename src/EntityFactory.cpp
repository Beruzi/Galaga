#include "EntityFactory.h"

EntityFactory::EntityFactory() {}
EntityFactory::~EntityFactory() {}


// TODO: Make sure Entity Constructors align with the Factory Constructions
Entity* EntityFactory::createPlayer(float winX, float winY) {
    return new Player(winX, winY, 32, 32);
}
Entity* EntityFactory::createAlien(Alien::AlienType type, float winX, float winY) {
    return new Alien(type, winX, winY, 32, 32);   
} 