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

void SnakeFood::GenerateNewLocation(int maxLocation)
{
    sf::Vector2f newPosition;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, maxLocation);
    newPosition.x = distribution(generator);
    newPosition.y = distribution(generator);
    snakeFoodObject.setPosition(newPosition);
}
