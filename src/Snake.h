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
public:
    Snake();
    Snake(sf::Vector2f head);
    // Instead of popping like in MoveSnake()
    // Simply add to deque
    sf::Vector2f GetSnakeHeadPosition();
    sf::RectangleShape GetSnakeHead();
    void DisplaySnake(sf::RenderWindow& window);
    void ExtendSnake();
    void MoveSnake(int snakeDirection); // Move only head body piece
};


#endif
