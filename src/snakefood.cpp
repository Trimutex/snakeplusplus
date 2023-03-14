// SnakeFood.cpp
#include <iostream>
#include <SFML\Graphics.hpp>
#include "common.h"
#include "snakeFood.h"


SnakeFood::SnakeFood()
{
    snakeFoodObject.setSize(sf::Vector2f(kGridSize,  kGridSize));
    snakeFoodObject.setFillColor(sf::Color::Red);
    return;
}

SnakeFood::SnakeFood(sf::Vector2f snakeFoodSize)
{
    snakeFoodObject.setSize(snakeFoodSize);
    snakeFoodObject.setFillColor(sf::Color::Red);
    return;
}

// Returns a new food object for the snakeFood
void SnakeFood::GenerateNewFood(sf::Vector2f windowSize)
{
    sf::Vector2f newPosition;
    newPosition.x = GenerateRandomNumber(windowSize.x);
    newPosition.y = GenerateRandomNumber(windowSize.y);
    snakeFoodObject.setPosition(newPosition);
    return;
}

sf::RectangleShape SnakeFood::GetFoodObject(void)
{
    return snakeFoodObject;
}

sf::Vector2f SnakeFood::GetFoodObjectPosition(void)
{
    return snakeFoodObject.getPosition();
}

// Returns a newly generated number
int SnakeFood::GenerateRandomNumber(int generationLimit)
{
    int generatedNumber;
    std::uniform_int_distribution<> distribution(0, generationLimit);
    generatedNumber = distribution(generator);
    generatedNumber -= (generatedNumber % kGridSize);
    return generatedNumber;
}
