#include <iostream>
#include <SFML\Main.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
using namespace std;

int main()
{
    int videoSizeHorizontal, videoSizeVertical;
    videoSizeHorizontal = 1280;
    videoSizeVertical = 720;
    sf::RenderWindow window(sf::VideoMode(videoSizeHorizontal, videoSizeVertical), "SnakePlusPlus");
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if ((event.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                window.close();
        }
    }
}
