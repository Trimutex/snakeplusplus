// Snake.cpp
#include <memory>
#include <queue>
#include <random>
#include <SFML/Graphics.hpp>
#include "snake.hpp"

namespace snakeplusplus
{
    // General constructor for snake class
    Snake::Snake(void)
    {
        return;
    }
    
    void Snake::Pop(void)
    {
        *(body.front().get()) = ' ';
        body.pop();
    }

    Food::Food()
    {
        return;
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
        std::uniform_int_distribution<> distribution(0, generationLimit);
        generatedNumber = distribution(generator);
        return generatedNumber;
    }
}
