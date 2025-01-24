#include "Player.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Class Basics
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Player::Player() {
    setSourceRect(184, 55, 15, 16);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Utility
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Player::enforceBounds() {
    // Adds a 5 pixel border padding
    if (winRect.x < 5) winRect.x = 5;
    if (winRect.y < 5) winRect.y = 5;
    if (winRect.x + winRect.w > 480 - 5) winRect.x = 480 - 5 - winRect.w;
    if (winRect.y + winRect.h > 640 - 5) winRect.y = 640 - 5 - winRect.h;
}





