// Snake.cpp
#include <iostream>
#include <queue>
#include <SFML/Graphics.hpp>
#include "common.h"
#include "snake.h"
#include "snakefood.h"

// General constructor for snake class
Snake::Snake(void)
{
    bodyPartSize = sf::Vector2f(kGridSize, kGridSize);
    CreateHead();
    return;
}

// Iterate through snake deque and draw to window
void Snake::DisplaySnake(sf::RenderWindow& window)
{
    for (auto snakeBodyPart = snakeBody.cbegin(); snakeBodyPart != snakeBody.cend(); ++snakeBodyPart)
        window.draw(*snakeBodyPart);
    return;
}

// Return the RectangleShape head of snake
sf::RectangleShape Snake::GetSnakeHead(void)
{
    sf::RectangleShape head;
    head = snakeBody.front();
    return head;
}

// Return the Vector2f head of snake
sf::Vector2f Snake::GetSnakeHeadPosition(void)
{
    sf::Vector2f position;
    position = snakeBody.front().getPosition();
    return position;
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

// Move snake based on direction and check for collision
void Snake::MoveSnake(SnakeFood* snakeFood)
{
    // TODO: Add losing on wall collision
    if (CheckBoundaries()) // Wall collision
    {
        gameFinished = true;
        return;
    }
    sf::Vector2f newHeadPosition;
    newHeadPosition = CalculateNewPosition(GetSnakeHeadPosition());
    sf::RectangleShape newBodyPart(sf::Vector2f(kGridSize, kGridSize));
    newBodyPart.setPosition(newHeadPosition);
    // TODO: Add losing on self collision
    if (IsSelfCollision(newBodyPart) && (snakeBody.size() > 1)) // Snake collision
    {
        gameFinished = true;
        return;
    }
    if (IsSelfCollision(newBodyPart))
        return;
    AddBodyPart(newBodyPart);
    if (!GlobalCollision(GetSnakeHeadPosition(), snakeFood->GetFoodObjectPosition()))
        snakeBody.pop_back();
    return;
}

void Snake::UpdateDirection(int newDirection)
{
    snakeDirection = newDirection;
    return;
}

void Snake::AddBodyPart(sf::RectangleShape newBodyPart)
{
    newBodyPart.setFillColor(sf::Color::Green);
    snakeBody.push_front(newBodyPart);
}

// Get a new coordinate position based on snake direction
sf::Vector2f Snake::CalculateNewPosition(sf::Vector2f position)
{
    if (snakeDirection == 0)
        return position;
    if (snakeDirection == kLeft)
        position.x -= kGridSize;
    if (snakeDirection == kUp)
        position.y -= kGridSize;
    if (snakeDirection == kDown)
        position.y += kGridSize;
    if (snakeDirection == kRight)
        position.x += kGridSize;
    return position;
}

// Check snake head for running into boundaries
bool Snake::CheckBoundaries(void)
{
    if (snakeBody.front().getPosition().x == 0 && snakeDirection == kLeft)
        return true;
    if (snakeBody.front().getPosition().y == 0 && snakeDirection == kUp)
        return true;
    // TODO: Change boundaries to not be hard-coded
    if (snakeBody.front().getPosition().y > 675 && snakeDirection == kDown)
        return true;
    if (snakeBody.front().getPosition().x > 975 && snakeDirection == kRight)
        return true;
    return false;
}

void Snake::CreateHead(void)
{
    sf::RectangleShape newBodyPart(bodyPartSize);
    newBodyPart.setFillColor(sf::Color::Green);
    snakeBody.push_front(newBodyPart);
}

// Test for snake self collision
bool Snake::IsSelfCollision(sf::RectangleShape testRectangle)
{
    for (auto snakeBodyPart = snakeBody.cbegin(); snakeBodyPart != snakeBody.cend(); ++snakeBodyPart)
        if (GlobalCollision(testRectangle.getPosition(), (*snakeBodyPart).getPosition()))
            return true;
    return false;
}
