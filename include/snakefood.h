// SnakeFood.h
#ifndef SNAKEFOOD_H
#define SNAKEFOOD_H

#include <SFML/Graphics.hpp>
#include <random>

class SnakeFood
{
public:
    SnakeFood();
    SnakeFood(sf::Vector2f snakeFoodSize);
    void GenerateNewFood(sf::Vector2f windowSize);
    sf::RectangleShape GetFoodObject(void);
    sf::Vector2f GetFoodObjectPosition(void);
protected:
    ;
private:
    sf::RectangleShape snakeFoodObject;
    std::default_random_engine generator;
    int GenerateRandomNumber(int generationLimit);
};

#endif
