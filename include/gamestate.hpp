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
        void SetGameSettings(int argc, char* argv[]);
        void StartGame(void);
        sf::Vector2f GetGameBoundaries(void);
    protected:
        ;
    private:
        std::vector< std::vector<char> > gameBoard;
        std::unique_ptr<DisplayInterface> graphics;
        Snake player;
        Food playerFood;
        Input playerInput;
        bool useSFML = 1;
        bool isGameOver = 0;
        void ApplySettings(void);
        void DisplayEndScreen(void);
        void GameLoop(void);
        void PlaceNewSnakePart(sf::Vector2f location);
        void PlayerWantsToContinue(void);
        void RegenerateFood(void);
        void ResetGameBoard(void);
        void RestartGame(void);
    };
}

#endif
