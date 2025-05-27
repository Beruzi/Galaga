#include <Player.h>

Player::Player() : Entity(184, 55, 15, 16), lives(3) {
    setWinRect(215.0, 304.0, 15.0, 16.0);
}

Player::~Player(){}



//  


void Player::shoot() {}
