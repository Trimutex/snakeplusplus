// Snake.h
#ifndef SNAKE_H
#define SNAKE_H
#include <queue>
#include "SnakeFood.h"


class Snake
{
private:
    std::deque<sf::RectangleShape> snakeBody;
    int snakeDirection = 0;
public:
    Snake();
    Snake(sf::Vector2f head);
    sf::Vector2f GetSnakeHeadPosition();
    sf::RectangleShape GetSnakeHead();
    void DisplaySnake(sf::RenderWindow& window);
    void MoveSnake(SnakeFood& playerFood, sf::VideoMode gameVideoMode);
    void SnakeFoodCollision(SnakeFood& snakeFood, sf::VideoMode gameVideoMode);
    void CheckDirection();
    bool CheckBoundaries();
    bool IsSelfCollision(sf::RectangleShape testRectangle);
};


#endif
