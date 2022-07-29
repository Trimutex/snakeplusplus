// GameState.h
#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState
{
private:
public:
    sf::VideoMode gameVideoMode;
    sf::RenderWindow gameWindow;
    /*
    gameGridHorizontal = (videoSizeHorizontal // 25) * 25;
    gameGridVertical = (videoSizeVertical // 25) * 25;
    */
    GameState();
    GameState(int newHorizontal, int newVertical);
    // sf::Vector2f GetGameBoundaries();
};

#endif
