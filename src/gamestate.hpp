// GameState.h
#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <SFML/Graphics.hpp>
#include "snake.hpp"
#include "playerinterface.hpp"

namespace snakeplusplus
{
    const int kUnitSpeed = 1;

    class GameEngine
    {
    public:
        GameEngine();
        void Start(void);
        void Reset(void);
        sf::Vector2f GetGameBoundaries(void);
    private:
        std::vector< std::vector<char> > gameBoard;
        PlayerOutput graphics;
        Snake player;
        Food playerFood;
        bool isGameOver = 0;
        bool isBotControlled = 1;
        void DisplayEndScreen(void);
        void Loop(void);
        sf::Vector2f MovePlayer(void);
        void PlaceNewSnakePart(sf::Vector2f location);
        void RegenerateFood(void);
        void PrepareGameBoard(void);
        void UpdatePlayerSpeed();
    };
}

#endif
