// Snake.h
#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <memory>
#include <queue>
#include <random>
#include <SFML/Graphics.hpp>
#include "common.hpp"

namespace snakeplusplus
{
    class Snake
    {
    public:
        Snake(void);
        PlayerDirection GetDirection(void);
        sf::Vector2f GetHeadLocation(void);
        sf::Vector2f Move(void);
        void Pop(void);
        sf::Vector2f Reset(void);
        void UpdateDirection(PlayerDirection newDirection);
    protected:
        ;
    private:
        std::queue< std::shared_ptr<char> > snakeBody;
        PlayerDirection direction = kNone;
        sf::Vector2f headLocation;
        void MoveLeft(void);
        void MoveUp(void);
        void MoveDown(void);
        void MoveRight(void);
    };

    class Food
    {
    public:
        Food();
        void GenerateNewFood(sf::Vector2f boundaries);
        sf::Vector2f GetFoodLocation(void);
    protected:
        ;
    private:
        std::shared_ptr<char> food;
        sf::Vector2f location;
        std::default_random_engine generator;
        int GenerateRandomNumber(int generationLimit);
    };
}

#endif
