// SnakeFood.cpp
#include "snakefood.h"


SnakeFood::SnakeFood()
{
    return;
}

// Returns a new food object for the snakeFood
void SnakeFood::GenerateNewFood(sf::Vector2f boundaries)
{
    location.x = GenerateRandomNumber(boundaries.x);
    location.y = GenerateRandomNumber(boundaries.y);
}

sf::Vector2f SnakeFood::GetFoodLocation(void)
{
    return location;
}

// Returns a newly generated number
int SnakeFood::GenerateRandomNumber(int generationLimit)
{
    int generatedNumber;
    std::uniform_int_distribution<> distribution(0, generationLimit);
    generatedNumber = distribution(generator);
    return generatedNumber;
}
