#include <Player.h>

Player::Player() : Entity() {} 
Player::Player(int srcX, int srcY, int w, int h) {}
Player::Player(int srcX, int srcY, int winX, int winY, int w, int h) {}


Player::~Player(){}


// Player Events
void Player::move(float dx, float dy) {
    Entity::move(dx, dy);
    enforceBounds();
}

void Player::shoot() {}



// Player Utility
void Player::enforceBounds() {
    // Adds a 5 pixel border padding
    if (winRect.x < 5) winRect.x = 5;
    if (winRect.y < 5) winRect.y = 5;
    if (winRect.x + winRect.w > 480 - 5) winRect.x = 480 - 5 - winRect.w;
    if (winRect.y + winRect.h > 640 - 5) winRect.y = 640 - 5 - winRect.h;
}
