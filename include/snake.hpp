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
        Snake(void);
        sf::Vector2f headLocation;
        sf::Vector2f speed;
        std::queue< std::shared_ptr<char> > body;
        void Pop(void);
    protected:
        ;
    private:
        ;
    };

    struct Food
    {
    public:
        Food(void);
        sf::Vector2f location;
        std::shared_ptr<char> food;
        void GenerateNewFood(sf::Vector2f boundaries);
    protected:
        ;
    private:
        std::default_random_engine generator;
        int GenerateRandomNumber(int generationLimit);
    };
}

#endif
