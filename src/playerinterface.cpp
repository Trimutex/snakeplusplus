#include "playerinterface.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace snakeplusplus 
{
    PlayerDirection GetPlayerInput(void)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) 
                || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            return kLeft;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
                || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            return kUp;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
                || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            return kDown;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
                || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            return kRight;
        return kNone;
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

    void PlayerOutput::CheckContinue(bool isBotControlled)
    {
        if (isBotControlled) { return; }
        DisplayEndScreen();
        while (true)
        {
            gameWindow.pollEvent(event);
            if ((event.type == sf::Event::Closed)
                    || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
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
        sf::Text gameOverText("Game Over\nPress 'Enter' to play again", font);
        gameOverText.setPosition(textPosition);
        gameWindow.draw(gameOverText);
        gameWindow.display();
        return;
    }

    void PlayerOutput::DisplayGameState(std::vector< std::vector<char> >& gameBoard)
    {
        CheckWindowEvents();
        char* letterOnBoard;
        for (float y = 0; y < gameBoundaries.y; y++)
        {
            for (float x = 0; x < gameBoundaries.x; x++)
            {
                letterOnBoard = &gameBoard.at(y).at(x);
                switch (*letterOnBoard)
                {
                    case 'O':
                        DrawSnake(sf::Vector2f(x, y));
                        break;
                    case 'X':
                        DrawFood(sf::Vector2f(x,y));
                        break;
                    default:
                        DrawEmpty(sf::Vector2f(x,y));
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
        while (gameWindow.pollEvent(event))
        {
            if ((event.type == sf::Event::Closed)
                    || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
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
