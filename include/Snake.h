// Snake.h
#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include <SFML\Graphics.hpp>
#include "SnakeFood.h"


class Snake
{
public:
    Snake(void);
    Snake(sf::Vector2f head);
    void DisplaySnake(sf::RenderWindow& window);
    sf::RectangleShape GetSnakeHead(void);
    sf::Vector2f GetSnakeHeadPosition(void);
    bool IsTouchingObject(sf::RectangleShape object);
    void MoveSnake(SnakeFood* playerFood);
    void UpdateDirection(int newDirection);
protected:
    ;
private:
    std::deque<sf::RectangleShape> snakeBody;
    int snakeDirection = 0;
    sf::Vector2f CalculateNewPosition(sf::Vector2f position);
    bool CheckBoundaries(void);
    bool IsSelfCollision(sf::RectangleShape testRectangle);
};


#endif
