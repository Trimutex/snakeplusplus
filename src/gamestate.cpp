// GameState.cpp
#include <SFML/Graphics.hpp>
#include "common.h"
#include "display.h"
#include "gamestate.h"

GameState::GameState()
{
    if (useSFML)
        graphics.reset(new SFML());
    else
        graphics.reset(new CommandLine());
    return;
}

void GameState::StartGame()
{
    ResetGameBoard();
    RunGameLoop();
    return;
}

// TODO: Reimplement for DisplayInterface
void GameState::DisplayEndScreen(void)
{
    // graphics->DisplayEndScreen();
    return;
}

sf::Vector2f GameState::GetGameBoundaries(void)
{
    return graphics->gameBoundaries;
}

// TODO: Reimplement for DisplayInterface
void GameState::GetKeyboardInput(void)
{
    // sf::Event event;
    // while (gameWindow.pollEvent(event))
    // {
    //     if ((event.type == SFML:Event::Closed) || 
    //         (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
    //         gameWindow.close();
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    //     player.UpdateDirection(kLeft);
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    //     player.UpdateDirection(kUp);
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    //     player.UpdateDirection(kDown);
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    //     player.UpdateDirection(kRight);
    return;
}

// TODO: Reimplement for DisplayInterface
bool GameState::PlayerWantsToContinue(void)
{
    // sf::Event event;
    // while (true)
    // {
    //     while (gameWindow.pollEvent(event))
    //     {
    //         if ((event.type == sf::Event::Closed) || 
    //             (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
    //             gameWindow.close();
    //         return false;
    //     }
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    //         return true;
    //     sf::sleep(delay);
    // }
}

// Generates new food until not colliding with player
void GameState::RegenerateFood(void)
{
    // Keep making new food until generating a valid spot
    while (player.IsTouchingObject(playerFood.GetFoodObject()))
        playerFood.GenerateNewFood(GetGameBoundaries());
    return;
}

void GameState::ResetGameBoard(void)
{
    gameBoard.clear();
    sf::Vector2f boardDimensions = GetGameBoundaries();
    gameBoard.resize(boardDimensions.y);
    for (int i = 0; i < boardDimensions.y; i++)
        for (int j = 0; j < boardDimensions.x; j++)
            gameBoard[i].push_back(' ');
    return;
}

void GameState::RunGameLoop(void)
{
    while (graphics->IsOpen())
    {
        GetKeyboardInput();
        player.MoveSnake(&playerFood);
        RegenerateFood();
        RenderWindow();
    }
    return;
}

// TODO: Reimplement for DisplayInterface
void GameState::RenderWindow(void)
{
    // gameWindow.clear();
    // player.DisplaySnake(gameWindow);
    // gameWindow.draw(playerFood.GetFoodObject());
    // gameWindow.display();
    // if (player.gameFinished)
    //     DisplayEndScreen();
    return;
}
