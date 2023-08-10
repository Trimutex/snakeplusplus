// Snake.h
#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <SFML/System/Vector2.hpp>
#include <memory>
#include <queue>
#include <random>
#include <SFML/Graphics.hpp>

namespace snakeplusplus
{
    struct Snake
    {
    public:
        sf::Vector2f headLocation;
        sf::Vector2f speed;
        std::queue<char*> body;
        void Pop(void);
    };

    struct Food
    {
    public:
        Food(void);
        sf::Vector2f location;
        char* food;
        void GenerateNewFood(sf::Vector2f boundaries);
    private:
        std::default_random_engine generator;
        int GenerateRandomNumber(int generationLimit);
    };
}

#endif
