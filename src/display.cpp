#include "display.h"
#include <iostream>
//#include <SFML/System.hpp>

DisplayInterface::DisplayInterface(void)
{
    ;
}

bool DisplayInterface::IsOpen(void)
{
    return isWindowAlive;
}

CommandLine::CommandLine(void)
{
    gameBoundaries.x = 1025 / kGridSize;
    gameBoundaries.y = 725 / kGridSize;
    return;
}

void CommandLine::CheckContinue(void)
{
    int placeholder;
    std::cout << "Press enter to play again.";
    std::cin >> placeholder;
    return;
}

void CommandLine::DisplayEndScreen(void)
{
    std::cout << "Game Over!" << std::endl;
    return;
}

void CommandLine::DisplayGameState(std::vector< std::vector<char> >* gameBoard)
{
    Clear();
    for (int i = 0; i < gameBoundaries.y; i++)
    {
        for (int j = 0; j < gameBoundaries.x; j++)
            std::cout << gameBoard->at(i).at(j);
        std::cout << std::endl;
    }
    sf::sleep(delay);
}

void CommandLine::StartGameWindow(void)
{
    isWindowAlive = true;
    return;
}

void CommandLine::Clear(void)
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}

SFML::SFML(void)
{
    gameVideoSettings = sf::VideoMode(1025, 725);
    drawObject.setSize(sf::Vector2f(kGridSize, kGridSize));
    return;
}

void SFML::CheckContinue(void)
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

void SFML::DisplayEndScreen(void)
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

void SFML::DisplayGameState(std::vector< std::vector<char> >* gameBoard)
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

void SFML::StartGameWindow(void)
{
    gameWindow.create(gameVideoSettings, "SnakePlusPlus");
    isWindowAlive = true;
    return;
}

void SFML::UpdateResolution(sf::Vector2i newResolution)
{
    gameVideoSettings.width = newResolution.x;
    gameVideoSettings.height = newResolution.y;
    gameBoundaries.x = gameVideoSettings.width / kGridSize;
    gameBoundaries.y = gameVideoSettings.height / kGridSize;
    gameWindow.create(gameVideoSettings, "SnakePlusPlus");
    return;
}

void SFML::CheckWindowEvents(void)
{
    sf::Event event;
    while (gameWindow.pollEvent(event))
    {
        if ((event.type == sf::Event::Closed) || 
            (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
            gameWindow.close();
    }
}

void SFML::DrawEmpty(sf::Vector2f location)
{
    location *= static_cast<float>(kGridSize);
    drawObject.setPosition(location);
    drawObject.setFillColor(sf::Color::Black);
    gameWindow.draw(drawObject);
    return;
}

void SFML::DrawFood(sf::Vector2f location)
{
    location *= static_cast<float>(kGridSize);
    drawObject.setPosition(location);
    drawObject.setFillColor(sf::Color::Red);
    gameWindow.draw(drawObject);
    return;
}

void SFML::DrawSnake(sf::Vector2f location)
{
    location *= static_cast<float>(kGridSize);
    drawObject.setPosition(location);
    drawObject.setFillColor(sf::Color::Green);
    gameWindow.draw(drawObject);
    return;
}
