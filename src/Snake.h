//Snake.h
#ifndef SNAKE_H
#define SNAKE_H
#include <queue>

bool SnakeCollision(sf::RectangleShape object1, sf::RectangleShape object2);
void SnakeMovement(sf::Keyboard keyboard);

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
    std::deque<sf::Vector2f> snakeBody;
public:
    void ExtendSnake(sf::Vector2f newLocation);
    void MoveSnake();
};


#endif
