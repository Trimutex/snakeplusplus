// GameState.h
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <memory>
#include <SFML\Graphics.hpp>
#include "snake.h"
#include "display.h"

class GameState
{
public:
    std::vector< std::vector<char> > gameBoard;
    bool useSFML = 1;
    GameState();
    GameState(int newHorizontal, int newVertical);
    void StartGame(void);
    sf::Vector2f GetGameBoundaries(void);
protected:
    ;
private:
    std::unique_ptr<DisplayInterface> graphics;
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
