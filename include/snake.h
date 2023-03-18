// Snake.h
#ifndef SNAKE_H
#define SNAKE_H

#include <queue>
#include <SFML/Graphics.hpp>


class Snake
{
public:
    Snake(void);
    sf::Vector2f MoveSnake(void);
    sf::Vector2f Pop(void);
    void UpdateDirection(int newDirection);
protected:
    ;
private:
    std::queue<sf::Vector2f> snakeBody;
    int snakeDirection = 0;
    sf::Vector2f CalculateNewHead();
    void CreateNewHead(sf::Vector2f);
};


#endif
