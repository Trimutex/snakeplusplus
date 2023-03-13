// GameState.h
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML\Graphics.hpp>
#include "Snake.h"

class GameState
{
public:
    GameState();
    GameState(int newHorizontal, int newVertical);
    void StartGame(void);
    sf::Vector2f GetGameBoundaries(void);
protected:
    ;
private:
    sf::RenderWindow gameWindow;
    sf::VideoMode gameVideoSettings;
    SnakeFood playerFood;
    Snake player;
    sf::Time delay;
    void DisplayEndScreen(void);
    void GetKeyboardInput(void);
    bool PlayerWantsToContinue(void);
    void RegenerateFood(void);
    void RunGameLoop(void);
    void RenderWindow(void);
};

#endif
