// #include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "Snake.h"
#include "SnakeFood.h"
#include "GameState.h"

GameState::GameState()
{
    sf::VideoMode tempVideoMode(1024, 725);
    gameVideoMode = tempVideoMode;
    sf::RenderWindow gameWindow(gameVideoMode, "SnakePlusPlus");
    return;
}

GameState::GameState(int newHorizontal, int newVertical)
{
    sf::VideoMode tempVideoMode(newHorizontal, newVertical);
    gameVideoMode = tempVideoMode;
    sf::RenderWindow tempWindow(gameVideoMode, "SnakePlusPlus");
    return;
}

void GameState::startNewGame()
{
    gameWindow.create(gameVideoMode, "SnakePlusPlus");
    sf::Time delay = sf::milliseconds(25);
    int snakeDirection = 0;
    Snake player(sf::Vector2f(25,25));
    SnakeFood playerFood(sf::Vector2f(25,25));

    while (gameWindow.isOpen())
    {
        sf::Event event;
        while (gameWindow.pollEvent(event))
        {
            if ((event.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                gameWindow.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            snakeDirection = 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            snakeDirection = 2;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            snakeDirection = 3;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            snakeDirection = 4;
        player.MoveSnake(playerFood.snakeFoodObject);
        gameWindow.clear();
        player.DisplaySnake(gameWindow);
        gameWindow.draw(playerFood.snakeFoodObject);
        gameWindow.display();
        sf::sleep(delay);
    }
}
