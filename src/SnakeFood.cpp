// SnakeFood.cpp
#include <iostream>
#include <SFML\Graphics.hpp>
#include "SnakeFood.h"
#include "Snake.h"

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
    newPosition.x = GenerateRandomNumber(horizontalLocation);
    newPosition.y = GenerateRandomNumber(verticalLocation);
    if (GlobalCollision(snakeFoodObject.getPosition(), newPosition))
        {
            std::cout << "Location error: " << newPosition.x << " " << newPosition.y << '\n';
            throw std::runtime_error("Error! New generation on same location");
        }
    snakeFoodObject.setPosition(newPosition);
    return;
}


int SnakeFood::GenerateRandomNumber(int generationLimit)
{
    int generatedNumber;
    std::uniform_int_distribution<> distribution(0, generationLimit);
    generatedNumber = distribution(generator);
    generatedNumber -= (generatedNumber % 25);
    return generatedNumber;
}
