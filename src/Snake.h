// Snake.h
#ifndef SNAKE_H
#define SNAKE_H

sf::Vector2f CalculateNewPosition(int direction, sf::Vector2f position);
bool GlobalCollision(sf::Vector2f object1Position, sf::Vector2f object2Position);

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
