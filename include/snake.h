// Snake.h
#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include <SFML/Graphics.hpp>
#include "snakefood.h"


class Snake
{
public:
    bool gameFinished = false;
    Snake(void);
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
    sf::Vector2f bodyPartSize;
    int snakeDirection = 0;
    void AddBodyPart(sf::RectangleShape newBodyPart);
    sf::Vector2f CalculateNewPosition(sf::Vector2f position);
    bool CheckBoundaries(void);
    void CreateHead(void);
    bool IsSelfCollision(sf::RectangleShape testRectangle);
};


#endif
