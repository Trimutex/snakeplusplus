#include "common.h"

// Test for collision between two object positions
bool GlobalCollision(sf::Vector2f object1Position, sf::Vector2f object2Position)
{
    if (object1Position.x != object2Position.x)
        return false;
    if (object1Position.y != object2Position.y)
        return false;
    return true;
}