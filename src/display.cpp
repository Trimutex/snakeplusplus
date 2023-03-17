#include "common.h"
#include "display.h"
//#include <SFML/System.hpp>

DisplayInterface::DisplayInterface(void)
{
    ;
}

bool DisplayInterface::IsOpen(void)
{
    return isGameStillRunning;
}

CommandLine::CommandLine(void)
{
    gameBoundaries.x = 1025 / kGridSize;
    gameBoundaries.y = 725 / kGridSize;
    return;
}

// TODO: Use cout for printing game to screen
void CommandLine::DisplayGameState(void)
{
    ;
}

void CommandLine::StartGame(void)
{
    isGameStillRunning = true;
    return;
}

// TODO: Setup making window
SFML::SFML(void)
{
    delay = sf::milliseconds(75);
    gameVideoSettings = sf::VideoMode(1025, 725);
    return;
}

void SFML::DisplayGameState(void)
{
    return;
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

void SFML::StartGame(void)
{
    gameWindow.create(gameVideoSettings, "SnakePlusPlus");
    isGameStillRunning = true;
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
