// SnakeFood.h
#ifndef SNAKEFOOD_H
#define SNAKEFOOD_H

#include <random>
#include <SFML\Graphics.hpp>

extern const int kGridSize;

class SnakeFood
{
public:
    SnakeFood();
    SnakeFood(sf::Vector2f snakeFoodSize);
    void GenerateNewFood(sf::Vector2f windowSize);
    sf::RectangleShape GetFoodObject(void);
protected:
    ;
private:
    sf::RectangleShape snakeFoodObject;
    std::default_random_engine generator;
    int GenerateRandomNumber(int generationLimit);
};

#endif
