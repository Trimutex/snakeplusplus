// Snake.cpp
#include <queue>
#include <random>
#include <SFML/Graphics.hpp>
#include "common.hpp"
#include "snake.hpp"

namespace snakeplusplus
{
    // General constructor for snake class
    Snake::Snake(void)
    {
        return;
    }

    PlayerDirection Snake::GetDirection(void)
    {
        return direction;
    }

    sf::Vector2f Snake::GetHeadLocation(void)
    {
        return headLocation;
    }

    // Update snake with location information
    sf::Vector2f Snake::Move(void)
    {
        if (direction == kLeft) MoveLeft();
        if (direction == kUp) MoveUp();
        if (direction == kDown) MoveDown();
        if (direction == kRight) MoveRight();
        return headLocation;
    }

    // Removes tail of snake
    void Snake::Pop(void)
    {
        *(snakeBody.front().get()) = ' ';
        snakeBody.pop();
        return;
    }

    sf::Vector2f Snake::Reset(void)
    {
        return sf::Vector2f(4,5);
    }

    void Snake::UpdateDirection(PlayerDirection newDirection)
    {
        direction = newDirection;
        return;
    }

    void Snake::MoveLeft(void)
    {
        headLocation.x -= 1;
        return;
    }

    void Snake::MoveUp(void)
    {
        headLocation.y -= 1;
        return;
    }

    void Snake::MoveDown(void)
    {
        headLocation.y += 1;
        return;
    }

    void Snake::MoveRight(void)
    {
        headLocation.x += 1;
        return;
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

    sf::Vector2f Food::GetFoodLocation(void)
    {
        return location;
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
