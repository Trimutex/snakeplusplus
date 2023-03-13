#ifndef COMMON_H
#define COMMON_H

#include <SFML\Graphics.hpp>

const int kGridSize = 25;

enum PlayerDirection
{
    kLeft = 1,
    kUp = 2,
    kDown = 3,
    kRight = 4
};

bool GlobalCollision(sf::Vector2f object1Position, sf::Vector2f object2Position);

#endif