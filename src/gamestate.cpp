// GameState.cpp
#include <string>
#include <SFML/Graphics.hpp>
#include "common.h"
#include "display.h"
#include "gamestate.h"

GameState::GameState()
{
    return;
}

void GameState::SetGameSettings(int argc, char* argv[])
{
    std::string convertedString;
    for (int i = 0; i < argc; i++)
    {
        convertedString = argv[i];
        if (convertedString == "--no-sfml")
            useSFML = false;
    }
}

void GameState::StartGame()
{
    ApplySettings();
    ResetGameBoard();
    graphics->StartGameWindow();
    RunGameLoop();
    return;
}

void GameState::ApplySettings(void)
{
    if (useSFML)
        graphics.reset(new SFML());
    else
        graphics.reset(new CommandLine());
    return;
}

// TODO: Reimplement for DisplayInterface
void GameState::DisplayEndScreen(void)
{
    graphics->DisplayEndScreen();
    return;
}

sf::Vector2f GameState::GetGameBoundaries(void)
{
    return graphics->gameBoundaries;
}

void GameState::GetKeyboardInput(void)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player.UpdateDirection(kLeft);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        player.UpdateDirection(kUp);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        player.UpdateDirection(kDown);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        player.UpdateDirection(kRight);
    return;
}

void GameState::PlaceNewSnakePart(sf::Vector2f location)
{
    gameBoard.at(location.y).at(location.x) = 'o';
    return;
}

void GameState::PlayerWantsToContinue(void)
{
   graphics->CheckContinue();
   return;
}

// Generates new food until not colliding with player
void GameState::RegenerateFood(void)
{
    sf::Vector2f newLocation = playerFood.GetFoodLocation();
    bool isUpdated = false;
    // Keep making new food until generating a valid spot
    while (gameBoard.at(newLocation.y).at(newLocation.x) == 'o')
    {
        isUpdated = true;
        playerFood.GenerateNewFood(GetGameBoundaries());
        newLocation = playerFood.GetFoodLocation();
    }
    if (isUpdated)
        gameBoard.at(newLocation.y).at(newLocation.x) = 'x';
    return;
}

void GameState::ResetGameBoard(void)
{
    gameBoard.clear();
    sf::Vector2f boardDimensions = GetGameBoundaries();
    std::vector<char> tempBoard;
    tempBoard.resize(boardDimensions.x, ' ');
    gameBoard.resize(boardDimensions.y, tempBoard);
    playerFood.GenerateNewFood(boardDimensions);
    sf::Vector2f foodStartLocation = playerFood.GetFoodLocation();
    gameBoard.at(foodStartLocation.y).at(foodStartLocation.x) = 'x';

    return;
}

void GameState::RunGameLoop(void)
{
    while (graphics->IsOpen())
    {
        GetKeyboardInput();
        PlaceNewSnakePart(player.MoveSnake());
        RegenerateFood();
        graphics->DisplayGameState(&gameBoard);
        if (isGameOver)
            PlayerWantsToContinue();
    }
    return;
}

