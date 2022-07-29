#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "GameState.h"

GameState::GameState()
{
    videoSizeHorizontal = 1024;
    videoSizeVertical = 725;
    // sf::Vector2u newVideoSize(videoSizeHorizontal, videoSizeVertical);
    // window.setSize(newVideoSize);
    // window.setTitle("SnakePlusPlus");
    return;
}

GameState::GameState(int newHorizontal, int newVertical)
{
    videoSizeHorizontal = newHorizontal;
    videoSizeVertical = newVertical;
    // sf::Vector2u newVideoSize(videoSizeHorizontal, videoSizeVertical);
    // window.setSize(newVideoSize);
    // window.setTitle("SnakePlusPlus");
    return;
}
