// SnakeFood.h
#ifndef SNAKEFOOD_H
#define SNAKEFOOD_H
#include <SFML\Graphics.hpp>

class SnakeFood
{
private:
public:
    sf::RectangleShape snakeFoodObject;
    SnakeFood();
    SnakeFood(sf::Vector2f snakeFoodSize);
    void GenerateNewLocation(int maxLocation);
};

#endif
