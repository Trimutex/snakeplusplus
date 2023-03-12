// SnakeFood.cpp
#include <iostream>
#include <SFML\Graphics.hpp>
#include "SnakeFood.h"

const int kGridSize = 25;

SnakeFood::SnakeFood()
{
    snakeFoodObject.setSize(sf::Vector2f(kGridSize,kGridSize));
    snakeFoodObject.setFillColor(sf::Color::Red);
}

SnakeFood::SnakeFood(sf::Vector2f snakeFoodSize)
{
    snakeFoodObject.setSize(snakeFoodSize);
    snakeFoodObject.setFillColor(sf::Color::Red);
}

// Returns a new food object for the snakeFood
void SnakeFood::GenerateNewFood(sf::Vector2f windowSize)
{
    sf::Vector2f newPosition;
    newPosition.x = GenerateRandomNumber(windowSize.x);
    newPosition.y = GenerateRandomNumber(windowSize.y);
    snakeFoodObject.setPosition(newPosition);
    // if (GlobalCollision(snakeFoodObject.getPosition(), newPosition))
    // {
    //     std::cout << "Location error: " << newPosition.x << " " << newPosition.y << '\n';
    //     throw std::runtime_error("Error! New generation on same location");
    // }
}

sf::RectangleShape SnakeFood::GetFoodObject(void)
{
    return snakeFoodObject;
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
