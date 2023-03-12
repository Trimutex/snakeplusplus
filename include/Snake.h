// Snake.h
#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include <SFML\Graphics.hpp>
#include "SnakeFood.h"

sf::Vector2f CalculateNewPosition(int direction, sf::Vector2f position);
bool GlobalCollision(sf::Vector2f object1Position, sf::Vector2f object2Position);

class Snake
{
public:
    Snake();
    Snake(sf::Vector2f head);
    sf::Vector2f GetSnakeHeadPosition();
    sf::RectangleShape GetSnakeHead();
    void DisplaySnake(sf::RenderWindow& window);
    void MoveSnake(SnakeFood& playerFood, sf::VideoMode gameVideoMode);
    void CheckDirection();
    bool CheckBoundaries();
    bool IsSelfCollision(sf::RectangleShape testRectangle);
    bool IsTouchingObject(sf::RectangleShape object);
protected:
    ;
private:
    std::deque<sf::RectangleShape> snakeBody;
    int snakeDirection = 0;
};


#endif
