#include <iostream>
#include <stdlib.h>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "GameState.h"
#include "Snake.h"

int main()
{
    GameState newGame;
    newGame.gameWindow.create(newGame.gameVideoMode, "SnakePlusPlus");
    sf::RenderWindow *window = &newGame.gameWindow;
    sf::Time delay = sf::milliseconds(25);
    int snakeDirection = 0;
    Snake Player(sf::Vector2f(25,25));
    sf::RectangleShape snakeHead(sf::Vector2f(25,25));
    sf::RectangleShape snakeFood(sf::Vector2f(25,25));
    snakeFood.setFillColor(sf::Color::Red);
    snakeFood.setPosition(25,25);

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if ((event.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                window->close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            snakeDirection = 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            snakeDirection = 2;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            snakeDirection = 3;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            snakeDirection = 4;
        Player.MoveSnake(snakeFood);
        window->clear();
        window->draw(snakeFood);
        Player.DisplaySnake(*window);
        window->display();
        sf::sleep(delay);
    }
}
