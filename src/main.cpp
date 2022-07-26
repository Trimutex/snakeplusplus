#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "Snake.h"


/*

    TODO:    Work on snake body
    Add ability for body to extend when eating food

    Turn snake body into queue
    Each piece of queue has coordinates
    If head touches food, just add to queue, don't pop

*/



int main()
{
    int videoSizeHorizontal, videoSizeVertical;
    videoSizeHorizontal = 1024;
    videoSizeVertical = 725;
    sf::RenderWindow window(sf::VideoMode(videoSizeHorizontal, videoSizeVertical), "SnakePlusPlus");
    sf::Time delay = sf::milliseconds(100);

    Snake Player(sf::Vector2f(25,25));
    sf::RectangleShape snakeHead(sf::Vector2f(25,25));
    sf::RectangleShape snakeFood(sf::Vector2f(25,25));
    snakeHead.setFillColor(sf::Color::Green);
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
        sf::Vector2f snakeHeadPosition = Player.GetHeadPosition();
        sf::Vector2f snakeFoodPosition = snakeFood.getPosition();
        // TODO:    Split Movement into separate function
        //          Add boundaries
        //          Add movement until boundaries
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            snakeHeadPosition.x -= 25;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            snakeHeadPosition.y -= 25;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            snakeHeadPosition.y += 25;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            snakeHeadPosition.x += 25;
        snakeHead.setPosition(snakeHeadPosition.x, snakeHeadPosition.y);
        if (SnakeCollision(snakeHead, snakeFood))
        {
            snakeFoodPosition.x += 25;
            snakeFoodPosition.y += 25;
            snakeFood.setPosition(snakeFoodPosition.x, snakeFoodPosition.y);
        }
        window.clear();
        window.draw(snakeFood);
        window.draw(snakeHead);
        window.display();
        sf::sleep(delay);
    }
}
