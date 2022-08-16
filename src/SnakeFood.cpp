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

int SnakeFood::GenerateNewLocation(int maxLocation)
{
    int newPosition;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, maxLocation);
    newPosition = distribution(generator);
    return newPosition;
}
