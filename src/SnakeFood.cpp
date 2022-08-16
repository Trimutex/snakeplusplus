// SnakeFood.cpp
#include <random>
#include "SnakeFood.h"

SnakeFood::SnakeFood()
{
    snakeFoodObject.setSize(sf::Vector2f(25,25));
    snakeFoodObject.setFillColor(sf::Color::Red);
}

SnakeFood::SnakeFood(sf::Vector2f snakeFoodSize)
{
    snakeFoodObject.setSize(snakeFoodSize);
    snakeFoodObject.setFillColor(sf::Color::Red);
}

void SnakeFood::GenerateNewLocation(int horizontalLocation, int verticalLocation)
{
    sf::Vector2f newPosition;
    std::default_random_engine generator(time(NULL));
    std::uniform_int_distribution<int> distributionX(0, horizontalLocation);
    std::uniform_int_distribution<int> distributionY(0, verticalLocation);
    int newX = distributionX(generator);
    int newY = distributionY(generator);
    newX = newX - (newX % 25) - 25;
    newY = newY - (newY % 25) - 25;
    newPosition.x = newX;
    newPosition.y = newY;
    snakeFoodObject.setPosition(newPosition);
    return;
}
