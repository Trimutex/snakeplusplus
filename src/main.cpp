#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
using namespace std;

bool SnakeCollision(sf::RectangleShape object1, sf::RectangleShape object2);

int main()
{
    int videoSizeHorizontal, videoSizeVertical;
    videoSizeHorizontal = 1024;
    videoSizeVertical = 725;
    sf::RenderWindow window(sf::VideoMode(videoSizeHorizontal, videoSizeVertical), "SnakePlusPlus");
    sf::Time delay = sf::milliseconds(100);

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
        sf::Vector2f snakeHeadPosition = snakeHead.getPosition();
        sf::Vector2f snakeFoodPosition = snakeFood.getPosition();
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

bool SnakeCollision(sf::RectangleShape object1, sf::RectangleShape object2)
{
    sf::Vector2f object1Position = object1.getPosition();
    sf::Vector2f object2Position = object2.getPosition();
    if (object1Position.x != object2Position.x)
        return 0;
    if (object1Position.y != object2Position.y)
        return 0;

    return 1;

}
