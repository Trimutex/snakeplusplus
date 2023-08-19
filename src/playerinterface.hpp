#ifndef PLAYERINTERFACE_HPP
#define PLAYERINTERFACE_HPP

#include "common.hpp"
#include <SFML/Graphics.hpp>

const int kGridSize = 25;

namespace snakeplusplus
{
    PlayerDirection GetPlayerInput(void);

    class PlayerOutput 
    {
    public:
        sf::Vector2f gameBoundaries;
        PlayerOutput(void);
        bool IsOpen(void);
        void CheckContinue(void);
        void DisplayGameState(std::vector< std::vector<char> >& gameBoard);
        void StartGameWindow(void);
    private:
        void CheckWindowEvents(void);
        void DisplayEndScreen(void);
        void DrawEmpty(sf::Vector2f location);
        void DrawFood(sf::Vector2f location);
        void DrawSnake(sf::Vector2f location);
        sf::RenderWindow gameWindow;
        sf::VideoMode gameVideoSettings;
        sf::RectangleShape drawObject;
        bool isWindowAlive;
        sf::Time delay = sf::milliseconds(20);
    };
}

#endif
