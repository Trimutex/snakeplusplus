// Snake.cpp
#include <queue>
#include <SFML/Graphics.hpp>
#include "common.h"
#include "snake.h"

// General constructor for snake class
Snake::Snake(void)
{
    CreateNewHead(sf::Vector2f(4,5));
    return;
}

// Move snake based on direction and check for collision
sf::Vector2f Snake::MoveSnake(void)
{
    sf::Vector2f newHeadPosition;
    newHeadPosition = CalculateNewHead();
    CreateNewHead(newHeadPosition);
    return newHeadPosition;
}

// Removes tail of snake
// Returns the location of the tail
sf::Vector2f Snake::Pop(void)
{
    sf::Vector2f tailLocation = snakeBody.front();
    snakeBody.pop();
    return tailLocation;
}

void Snake::UpdateDirection(int newDirection)
{
    snakeDirection = newDirection;
    return;
}

// Get a new coordinate position based on snake direction
sf::Vector2f Snake::CalculateNewHead(void)
{
    sf::Vector2f position = snakeBody.back();
    if (snakeDirection == kLeft)
        position.x -= 1;
    if (snakeDirection == kUp)
        position.y -= 1;
    if (snakeDirection == kDown)
        position.y += 1;
    if (snakeDirection == kRight)
        position.x += 1;
}

void Snake::CreateNewHead(sf::Vector2f headLocation)
{
    snakeBody.push(headLocation);
    return;
}
