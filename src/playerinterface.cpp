#include "playerinterface.hpp"
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>

namespace snakeplusplus 
{
    PlayerInput::PlayerInput(void)
    {
        lastPlayerInput = kNone;
    }

    PlayerDirection PlayerInput::GetPlayerInput(void)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            lastPlayerInput = kLeft;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            lastPlayerInput = kUp;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            lastPlayerInput = kDown;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            lastPlayerInput = kRight;
        return lastPlayerInput;
    }

    bool PlayerOutput::IsOpen(void)
    {
        return gameWindow.isOpen();
    }

    PlayerOutput::PlayerOutput(void)
    {
        float kWidth = 1025;
        float kHeight = 725;
        float kBoardWidth = kWidth / kGridSize;
        float kBoardHeight = kHeight / kGridSize;
        gameBoundaries = sf::Vector2f(kBoardWidth, kBoardHeight); 
        gameVideoSettings = sf::VideoMode(kWidth, kHeight);
        drawObject.setSize(sf::Vector2f(kGridSize, kGridSize));
        return;
    }

    void PlayerOutput::CheckContinue(void)
    {
        sf::Event event;
        DisplayEndScreen();
        while (true)
        {
            gameWindow.pollEvent(event);
            if ((event.type == sf::Event::Closed) || 
                (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
            {
                gameWindow.close();
                return;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) { return; }
            sf::sleep(delay);
        }
    }

    void PlayerOutput::DisplayEndScreen(void)
    {
        gameWindow.clear();
        sf::Vector2f textPosition(gameBoundaries);
        textPosition.x = textPosition.x / 2;
        textPosition.y = textPosition.y / 2;
        sf::Font font;
        font.loadFromFile("Arial.ttf");
        sf::Text gameOverText("Game Over", font);
        gameOverText.setPosition(textPosition);
        gameWindow.draw(gameOverText);
        gameWindow.display();
        return;
    }

    void PlayerOutput::DisplayGameState(std::vector< std::vector<char> >& gameBoard)
    {
        CheckWindowEvents();
        sf::Vector2f location;
        char* letterOnBoard;
        for (float y = 0; y < gameBoundaries.y; y++)
        {
            for (float x = 0; x < gameBoundaries.x; x++)
            {
                location.x = x;
                location.y = y;
                letterOnBoard = &gameBoard.at(location.y).at(location.x);
                switch (*letterOnBoard)
                {
                    case 'O':
                        DrawSnake(location);
                        break;
                    case 'X':
                        DrawFood(location);
                        break;
                    default:
                        DrawEmpty(location);
                        break;
                }
            }
        }
        gameWindow.display();
        sf::sleep(delay);
        return;
    }

    void PlayerOutput::StartGameWindow(void)
    {
        gameWindow.create(gameVideoSettings, "SnakePlusPlus");
        isWindowAlive = true;
        return;
    }

    void PlayerOutput::CheckWindowEvents(void)
    {
        sf::Event event;
        while (gameWindow.pollEvent(event))
        {
            if ((event.type == sf::Event::Closed) || 
                (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                gameWindow.close();
        }
    }

    void PlayerOutput::DrawEmpty(sf::Vector2f location)
    {
        location *= static_cast<float>(kGridSize);
        drawObject.setPosition(location);
        drawObject.setFillColor(sf::Color::Black);
        gameWindow.draw(drawObject);
        return;
    }

    void PlayerOutput::DrawFood(sf::Vector2f location)
    {
        location *= static_cast<float>(kGridSize);
        drawObject.setPosition(location);
        drawObject.setFillColor(sf::Color::Red);
        gameWindow.draw(drawObject);
        return;
    }

    void PlayerOutput::DrawSnake(sf::Vector2f location)
    {
        location *= static_cast<float>(kGridSize);
        drawObject.setPosition(location);
        drawObject.setFillColor(sf::Color::Green);
        gameWindow.draw(drawObject);
        return;
    }
}
