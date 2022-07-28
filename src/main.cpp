#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "Snake.h"

int main()
{
    int videoSizeHorizontal, videoSizeVertical;
    videoSizeHorizontal = 1024;
    videoSizeVertical = 725;
    /*
    gameGridHorizontal = (videoSizeHorizontal // 25) * 25;
    gameGridVertical = (videoSizeVertical // 25) * 25;
    */
    sf::RenderWindow window(sf::VideoMode(videoSizeHorizontal, videoSizeVertical), "SnakePlusPlus");
    sf::Time delay = sf::milliseconds(50);

    int snakeDirection = 0;
    Snake Player(sf::Vector2f(25,25));
    sf::RectangleShape snakeHead(sf::Vector2f(25,25));
    sf::RectangleShape snakeFood(sf::Vector2f(25,25));
    snakeFood.setFillColor(sf::Color::Red);

    snakeFood.setPosition(25,25);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if ((event.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                window.close();
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
        window.clear();
        window.draw(snakeFood);
        Player.DisplaySnake(window);
        window.display();
        sf::sleep(delay);
    }
}
