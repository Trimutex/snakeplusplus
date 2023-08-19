// Snake.h
#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <SFML/System/Vector2.hpp>
#include <queue>

namespace snakeplusplus
{
    struct Snake
    {
    public:
        sf::Vector2f headLocation;
        sf::Vector2f speed;
        std::queue<char*> body;
        void Pop(void);
        void Reset(void);
    };

    struct Food
    {
    public:
        sf::Vector2f location;
        char* food;
        void GenerateNewFood(sf::Vector2f boundaries);
    };
}

#endif
