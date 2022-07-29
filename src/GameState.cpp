#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
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
