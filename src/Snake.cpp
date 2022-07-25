#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "Snake.h"
using namespace std;

bool SnakeCollision(sf::RectangleShape object1, sf::RectangleShape object2)
{
    sf::Vector2f object1Position = object1.getPosition();
    sf::Vector2f object2Position = object2.getPosition();
    if (object1Position.x != object2Position.x)
        return 0;
    if (object1Position.y != object2Position.y)
        return 0;

    return 1;

}

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
    if (!snakeHead.isTouchingFood())
        snakeQueue.pop();

    */
    return;
}

void Snake::ExtendSnake(sf::Vector2f newLocation)
{
    /*
    snakeBody.push_back(newLocation);
    */
    return;
}

void Snake::MoveSnake()
{
    /*
    head.snakeBody()
    */
    return;
}
SnakeNode::SnakeNode();
SnakeNode::SnakeNode(sf::Vector2f addBodyPiece);
