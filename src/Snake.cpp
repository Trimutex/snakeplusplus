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
void SnakeMovement(sf::Keyboard keyboard)
{
    /*
    if (keyboard.pressed(Left))
        snakeHead.moveleft();
    if (keyboard.pressed(Right))
        snakeHead.moveRight();
    if (keyboard.pressed(Down))
        snakeHead.moveDown();
    if (keyboard.pressed(Up))
        snakeHead.moveUp();
    */
    return;
}

void Snake::ExtendSnake()
{
    // Create a new deque RectangleShape without popping old
    return;
}

void Snake::MoveSnake()
{
    // Create a new deque RectangleShape and pop old
    // Todo: Depreciate ExtendSnake and just add a collision test
    return;
}

// Get x and y position of snake head
sf::Vector2f Snake::GetHeadPosition()
{
    sf::Vector2f position;
    position = snakeBody.front().getPosition();
    return position;
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
    snakeBody.push_back(newBodyPart);
    return;
}
// SnakeNode::SnakeNode();
// SnakeNode::SnakeNode(sf::Vector2f addBodyPiece);
