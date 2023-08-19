// Snake.cpp
#include <queue>
#include <SFML/Graphics.hpp>
#include "common.hpp"
#include "snake.hpp"

namespace snakeplusplus
{
    void Snake::Pop(void)
    {
        *(body.front()) = ' ';
        body.pop();
        return;
    }

    void Snake::Reset(void)
    {
        while (!body.empty()) Pop();
        speed.x = 0;
        speed.y = 0;
        return;
    }

    // Returns a new food object for the snakeFood
    void Food::GenerateNewFood(sf::Vector2f boundaries)
    {
        location.x = snakeplusplus::GenerateRandomNumber(boundaries.x);
        location.y = snakeplusplus::GenerateRandomNumber(boundaries.y);
        return;
    }
}
