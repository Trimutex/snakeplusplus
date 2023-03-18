// GameState.h
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "snake.h"
#include "snakefood.h"
#include "display.h"

class GameState
{
public:
    GameState();
    void SetGameSettings(int argc, char* argv[]);
    void StartGame(void);
    sf::Vector2f GetGameBoundaries(void);
protected:
    ;
private:
    std::vector< std::vector<char> > gameBoard;
    std::unique_ptr<DisplayInterface> graphics;
    Snake player;
    SnakeFood playerFood;
    bool useSFML = 1;
    void ApplySettings(void);
    void DisplayEndScreen(void);
    void GetKeyboardInput(void);
    bool PlayerWantsToContinue(void);
    void RegenerateFood(void);
    void ResetGameBoard(void);
    void RunGameLoop(void);
    void RenderWindow(void);
};

#endif
