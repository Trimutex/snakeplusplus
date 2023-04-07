#include "playerinterface.hpp"
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
        return isWindowAlive;
    }

    PlayerOutput::PlayerOutput(void)
    {
        float kWidth = 1025 / kGridSize;
        float kHeight = 725 / kGridSize;
        gameBoundaries = sf::Vector2f(kWidth, kHeight); 
        gameVideoSettings = sf::VideoMode(1025, 725);
        drawObject.setSize(sf::Vector2f(kGridSize, kGridSize));
        return;
    }

    void PlayerOutput::CheckContinue(void)
    {
        sf::Event event;
        while (true)
        {
            while (gameWindow.pollEvent(event))
            {
                if ((event.type == sf::Event::Closed) || 
                    (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                    gameWindow.close();
                return;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                return;
            sf::sleep(delay);
        }
    }

    void PlayerOutput::DisplayEndScreen(void)
    {
        gameWindow.clear();
        sf::Vector2f textPosition(gameBoundaries);
        textPosition.x = textPosition.x / 2;
        textPosition.y = textPosition.y / 2;
        sf::Text gameOverText;
        gameOverText.setString("Game Over");
        gameOverText.setCharacterSize(30);
        gameOverText.setPosition(textPosition);
        gameWindow.draw(gameOverText);
        gameWindow.display();
        // if (!PlayerWantsToContinue())
        //     return;
        // player = Snake();
        // playerFood.GenerateNewFood(GetGameBoundaries());
        // gameWindow.clear();
        return;
    }

    void PlayerOutput::DisplayGameState(std::vector< std::vector<char> >* gameBoard)
    {
        CheckWindowEvents();
        sf::Vector2i location(0,0);
        char letterOnBoard;
        for (; location.y < gameBoundaries.y; location.y++)
        {
            for (; location.x < gameBoundaries.x; location.x++)
            {
                letterOnBoard = gameBoard->at(location.y).at(location.y);
                if (letterOnBoard == 'o')
                    DrawSnake(static_cast<sf::Vector2f>(location));
                else if (letterOnBoard == 'x')
                    DrawFood(static_cast<sf::Vector2f>(location));
                else
                    DrawEmpty(static_cast<sf::Vector2f>(location));
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
