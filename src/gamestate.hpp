// GameState.h
#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include "snake.hpp"
#include "playerinterface.hpp"

namespace snakeplusplus
{
    class GameEngine
    {
    public:
        GameEngine();
        void StartGame(void);
        sf::Vector2f GetGameBoundaries(void);
    private:
        std::vector< std::vector<char> > gameBoard;
        PlayerInput controls;
        PlayerOutput graphics;
        Snake player;
        Food playerFood;
        bool useSFML = 1;
        bool isGameOver = 0;
        void DisplayEndScreen(void);
        void GameLoop(void);
        sf::Vector2f MovePlayer(void);
        void PlaceNewSnakePart(sf::Vector2f location);
        void RegenerateFood(void);
        void PrepareGameBoard(void);
        void UpdatePlayerSpeed();
    };
}

#endif
