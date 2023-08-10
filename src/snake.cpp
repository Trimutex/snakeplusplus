// Snake.cpp
#include <algorithm>
#include <memory>
#include <queue>
#include <random>
#include <SFML/Graphics.hpp>
#include "snake.hpp"

namespace snakeplusplus
{
    void Snake::Pop(void)
    {
        *(body.front()) = ' ';
        body.pop();
    }

    Food::Food(void)
    {
        generator.seed(std::random_device{}());
    }

    // Returns a new food object for the snakeFood
    void Food::GenerateNewFood(sf::Vector2f boundaries)
    {
        location.x = GenerateRandomNumber(boundaries.x);
        location.y = GenerateRandomNumber(boundaries.y);
    }

    // Returns a newly generated number
    int Food::GenerateRandomNumber(int generationLimit)
    {
        int generatedNumber;
        std::uniform_int_distribution<> distribution(0, generationLimit - 1);
        generatedNumber = distribution(generator);
        return generatedNumber;
    }
}