#include <random>
#include <SFML\Graphics.hpp>
#include "GeneralFunctions.h"


// Get a new coordinate position based on snake direction
sf::Vector2f CalculateNewPosition(int direction, sf::Vector2f position)
{
    if (direction == 0)
        return position;
    if (direction == 1)
        position.x -= 25;
    if (direction == 2)
        position.y -= 25;
    if (direction == 3)
        position.y += 25;
    if (direction == 4)
        position.x += 25;
    return position;
}

// Test for collision between two object positions
bool GlobalCollision(sf::Vector2f object1Position, sf::Vector2f object2Position)
{
    if (object1Position.x != object2Position.x)
        return 0;
    if (object1Position.y != object2Position.y)
        return 0;

    return 1;
}

int GenerateRandomNumber(int generationLimit)
{
    int generatedNumber;
    std::default_random_engine generator;
    std::uniform_int_distribution<> distribution(0, generationLimit);
    generatedNumber = distribution(generator);
    generatedNumber -= (generatedNumber % 25);
    return generatedNumber;
}