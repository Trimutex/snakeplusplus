#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
using namespace std;

int main()
{
    int videoSizeHorizontal, videoSizeVertical;
    videoSizeHorizontal = 1024;
    videoSizeVertical = 725;
    sf::RenderWindow window(sf::VideoMode(videoSizeHorizontal, videoSizeVertical), "SnakePlusPlus");
    sf::Time delay = sf::milliseconds(100);

    sf::RectangleShape snakeHead(sf::Vector2f(25,25));
    snakeHead.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if ((event.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                window.close();
        }
        sf::Vector2f snakeHeadPosition = snakeHead.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            snakeHeadPosition.x -= 25;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            snakeHeadPosition.y -= 25;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            snakeHeadPosition.y += 25;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            snakeHeadPosition.x += 25;
        snakeHead.setPosition(snakeHeadPosition.x, snakeHeadPosition.y);
        window.clear();
        window.draw(snakeHead);
        window.display();
        sf::sleep(delay);
    }
}
