// SnakeFood.h
#ifndef SNAKEFOOD_H
#define SNAKEFOOD_H

#include <SFML/Graphics.hpp>
#include <random>

class SnakeFood
{
public:
    SnakeFood();
    void GenerateNewFood(sf::Vector2f boundaries);
    sf::Vector2f GetFoodLocation(void);
protected:
    ;
private:
    sf::Vector2f location;
    std::default_random_engine generator;
    int GenerateRandomNumber(int generationLimit);
};

#endif
