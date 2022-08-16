// GameState.h
#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <SFML\Graphics.hpp>

class GameState
{
private:
public:
    sf::VideoMode gameVideoMode;
    sf::RenderWindow gameWindow;
    GameState();
    GameState(int newHorizontal, int newVertical);
    void startNewGame();
    /*
    gameGridHorizontal = (videoSizeHorizontal // 25) * 25;
    gameGridVertical = (videoSizeVertical // 25) * 25;
    */
    // sf::Vector2f GetGameBoundaries();
};

#endif
