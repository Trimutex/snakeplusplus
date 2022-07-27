#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "Snake.h"

// Test for collision between two objects
bool SnakeCollision(sf::RectangleShape object1, sf::RectangleShape object2)
{
    // Hack for getting a temporary collision
    // Collision only tested for origin corrordinate
    sf::Vector2f object1Position = object1.getPosition();
    sf::Vector2f object2Position = object2.getPosition();
    if (object1Position.x != object2Position.x)
        return 0;
    if (object1Position.y != object2Position.y)
        return 0;

    return 1;

}

// Move snake head piece
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
        return 1;
    if (snakeBody.front().getPosition().y == 0 && snakeDirection == 2)
        return 1;
    // TODO: Change boundaries to not be hard-coded
    if (snakeBody.front().getPosition().y > 675 && snakeDirection == 3)
        return 1;
    if (snakeBody.front().getPosition().x > 975 && snakeDirection == 4)
        return 1;
    return 0;
}

// Get a new coordinate position based on snake direction
sf::Vector2f CalculateNewPosition(int direction, sf::Vector2f position)
{
    if (direction == 0)
        return position;
    if (direction == 1)
        position.x -= 25;
    if (direction == 2)
        position.y -= 25;
    if (direction == 3)
        position.y += 25;
    if (direction == 4)
        position.x += 25;
    return position;
}

void Snake::ExtendSnake()
{
    // Create a new deque RectangleShape without popping old
    return;
}

void Snake::MoveSnake(sf::RectangleShape& snakeFood)
{
    // Create a new deque RectangleShape and pop old
    // Todo: Depreciate ExtendSnake and just add a collision test
    CheckDirection();
    sf::Vector2f newHeadPosition;
    newHeadPosition = GetSnakeHeadPosition();
    if (!CheckBoundaries())
        newHeadPosition = CalculateNewPosition(snakeDirection, newHeadPosition);
    sf::RectangleShape newBodyPart(sf::Vector2f(25,25));
    newBodyPart.setPosition(newHeadPosition);
    snakeBody.push_front(newBodyPart);
    if (!SnakeCollision(GetSnakeHead(), snakeFood))
        snakeBody.pop_back();
    else if (SnakeCollision(GetSnakeHead(), snakeFood))
    {
        sf::Vector2f snakeFoodPosition = snakeFood.getPosition();
        snakeFoodPosition.x += 25;
        snakeFoodPosition.y += 25;
        snakeFood.setPosition(snakeFoodPosition.x, snakeFoodPosition.y);
    }
    return;
}

// Get x and y position of snake head
sf::Vector2f Snake::GetSnakeHeadPosition()
{
    sf::Vector2f position;
    position = snakeBody.front().getPosition();
    return position;
}

sf::RectangleShape Snake::GetSnakeHead()
{
    sf::RectangleShape head;
    head = snakeBody.front();
    return head;
}

void Snake::DisplaySnake(sf::RenderWindow& window)
{
    for (auto it = snakeBody.cbegin(); it != snakeBody.cend(); ++it)
    {
        window.draw(*it);
    }
    return;
}

Snake::Snake()
{
    // Possibly unnecessary
    // The big 3 could be used to create a fresh game state
    return;
}
Snake::Snake(sf::Vector2f head)
{
    sf::RectangleShape newBodyPart(head);
    newBodyPart.setFillColor(sf::Color::Green);
    snakeBody.push_back(newBodyPart);
    return;
}
// SnakeNode::SnakeNode();
// SnakeNode::SnakeNode(sf::Vector2f addBodyPiece);
