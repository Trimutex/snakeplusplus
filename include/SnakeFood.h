// SnakeFood.h
#ifndef SNAKEFOOD_H
#define SNAKEFOOD_H
#include <random>
#include <SFML\Graphics.hpp>

class SnakeFood
{
private:
public:
    sf::RectangleShape snakeFoodObject;
    std::default_random_engine generator;
    SnakeFood();
    SnakeFood(sf::Vector2f snakeFoodSize);
    void GenerateNewLocation(int horizontalLocation, int verticalLocation);
    int GenerateRandomNumber(int generationLimit);
};

#endif
