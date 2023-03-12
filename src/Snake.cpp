// Snake.cpp
#include <iostream>
#include <queue>
#include <SFML\Graphics.hpp>
#include "Snake.h"
#include "SnakeFood.h"

// General constructor for snake class
Snake::Snake()
{
    sf::RectangleShape newBodyPart(sf::Vector2f(kGridSize, kGridSize));
    newBodyPart.setFillColor(sf::Color::Green);
    snakeBody.push_back(newBodyPart);
    return;
}

// Constructor for snake with position
Snake::Snake(sf::Vector2f headSize)
{
    sf::RectangleShape newBodyPart(headSize);
    newBodyPart.setFillColor(sf::Color::Green);
    snakeBody.push_back(newBodyPart);
    return;
}

// Get a new coordinate position based on snake direction
sf::Vector2f CalculateNewPosition(int direction, sf::Vector2f position)
{
    if (direction == 0)
        return position;
    if (direction == 1)
        position.x -= kGridSize;
    if (direction == 2)
        position.y -= kGridSize;
    if (direction == 3)
        position.y += kGridSize;
    if (direction == 4)
        position.x += kGridSize;
    return position;
}

// Test for collision between two object positions
bool GlobalCollision(sf::Vector2f object1Position, sf::Vector2f object2Position)
{
    if (object1Position.x != object2Position.x)
        return 0;
    if (object1Position.y != object2Position.y)
        return 0;

    return 1;
}

// Check keyboard for new direction of snake
void Snake::CheckDirection()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        snakeDirection = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        snakeDirection = 2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        snakeDirection = 3;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        snakeDirection = 4;
    return;
}

// Check snake head for running into boundaries
bool Snake::CheckBoundaries()
{
    if (snakeBody.front().getPosition().x == 0 && snakeDirection == 1)
        return true;
    if (snakeBody.front().getPosition().y == 0 && snakeDirection == 2)
        return true;
    // TODO: Change boundaries to not be hard-coded
    if (snakeBody.front().getPosition().y > 675 && snakeDirection == 3)
        return true;
    if (snakeBody.front().getPosition().x > 975 && snakeDirection == 4)
        return true;
    return false;
}

// Move snake based on direction and test for eating food
void Snake::MoveSnake(SnakeFood& snakeFood, sf::VideoMode gameVideoMode)
{
    // CheckDirection();
    sf::Vector2f newHeadPosition;
    newHeadPosition = GetSnakeHeadPosition();
    if (CheckBoundaries())
        return;
    newHeadPosition = CalculateNewPosition(snakeDirection, newHeadPosition);
    sf::RectangleShape newBodyPart(sf::Vector2f(kGridSize, kGridSize));
    newBodyPart.setPosition(newHeadPosition);
    if (IsSelfCollision(newBodyPart)) // Do nothing if self collision
    {
        return;
    }
    newBodyPart.setFillColor(sf::Color::Green);
    snakeBody.push_front(newBodyPart);
    if (!GlobalCollision(GetSnakeHead().getPosition(), snakeFood.GetFoodObject().getPosition()))
        snakeBody.pop_back();
    return;
}

// Return the Vector2f head of snake
sf::Vector2f Snake::GetSnakeHeadPosition()
{
    sf::Vector2f position;
    position = snakeBody.front().getPosition();
    return position;
}

// Return the RectangleShape head of snake
sf::RectangleShape Snake::GetSnakeHead()
{
    sf::RectangleShape head;
    head = snakeBody.front();
    return head;
}

// Iterate through snake deque and draw to window
void Snake::DisplaySnake(sf::RenderWindow& window)
{
    for (auto it = snakeBody.cbegin(); it != snakeBody.cend(); ++it)
    {
        window.draw(*it);
    }
    return;
}

// Test for snake self collision
bool Snake::IsSelfCollision(sf::RectangleShape testRectangle)
{
    for (auto it = snakeBody.cbegin(); it != snakeBody.cend(); ++it)
    {
        if (GlobalCollision(testRectangle.getPosition(), (*it).getPosition()))
        {
            return true;
        }
    }
    return false;
}

// Checks if snake position matches object position
bool Snake::IsTouchingObject(sf::RectangleShape object)
{
    for (auto snakeBodyPart = snakeBody.cbegin(); snakeBodyPart != snakeBody.cend(); ++snakeBodyPart)
    {
        if ((*snakeBodyPart).getPosition().x != object.getPosition().x)
            continue;
        if ((*snakeBodyPart).getPosition().y != object.getPosition().y)
            continue;
        return true;
    }
    return false;
}
