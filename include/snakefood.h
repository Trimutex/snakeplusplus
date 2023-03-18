// SnakeFood.h
#ifndef SNAKEFOOD_H
#define SNAKEFOOD_H

#include <SFML/Graphics.hpp>
#include <random>

class SnakeFood
{
public:
    SnakeFood();
    sf::Vector2f GenerateNewFood(sf::Vector2f boundaries);
protected:
    ;
private:
    sf::Vector2f location;
    std::default_random_engine generator;
    int GenerateRandomNumber(int generationLimit);
};

#endif
