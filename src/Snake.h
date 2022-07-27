//Snake.h
#ifndef SNAKE_H
#define SNAKE_H
#include <queue>

bool SnakeCollision(sf::RectangleShape object1, sf::RectangleShape object2);
int SnakeMovement();
sf::Vector2f CalculateNewPosition(int direction, sf::Vector2f position);

// class SnakeNode
// {
// private:
//     // sf::RectangleShape snakeBody(sf::Vector2f(25,25));
//     sf::Vector2f snakeBodyLocation;
//     SnakeNode* next;
// public:
//     SnakeNode();
//     SnakeNode(sf::Vector2f addBodyPiece);
// };

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
    void ExtendSnake();
    void MoveSnake(sf::RectangleShape& snakeFood);
    void CheckDirection();
    bool CheckBoundaries();
};


#endif
