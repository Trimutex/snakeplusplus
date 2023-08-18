// GameState.cpp
#include <stdexcept>
#include <SFML/Graphics.hpp>
#include "common.hpp"
#include "playerinterface.hpp"
#include "gamestate.hpp"

namespace snakeplusplus
{
    GameEngine::GameEngine()
    {
        return;
    }

    void GameEngine::StartGame()
    {
        //ApplySettings();
        PrepareGameBoard();
        graphics.StartGameWindow();
        GameLoop();
        return;
    }

    void GameEngine::GameLoop(void)
    {
        while (graphics.IsOpen())
        {
            if (isGameOver)
            {
                graphics.CheckContinue();
                player.Reset();
                PrepareGameBoard();
                isGameOver = 0;
            }
            UpdatePlayerSpeed();
            PlaceNewSnakePart(MovePlayer());
            RegenerateFood();
            graphics.DisplayGameState(gameBoard);
        }
        return;
    }

    sf::Vector2f GameEngine::MovePlayer(void)
    {
        sf::Vector2f newHeadPosition;
        newHeadPosition.x = player.headLocation.x + player.speed.x;
        newHeadPosition.y = player.headLocation.y + player.speed.y;
        return newHeadPosition;
    }

    sf::Vector2f GameEngine::GetGameBoundaries(void)
    {
        return graphics.gameBoundaries;
    }

    void GameEngine::PlaceNewSnakePart(sf::Vector2f location)
    {
        try 
        {
            char* locationState;
            locationState = &gameBoard.at(location.y).at(location.x);
            if (*locationState == 'O' && player.body.size() > 1)
                isGameOver = true; // Game should end (Snake touching snake)
            *locationState = 'O';
            player.body.push(locationState);
            player.headLocation = location;
            if (playerFood.location != location)
                player.Pop();
        } catch (const std::out_of_range& error) {
            isGameOver = true; // Snake ran into edge
        }
    }

    // Generates new food until not colliding with player
    void GameEngine::RegenerateFood(void)
    {
        sf::Vector2f newLocation = playerFood.location;
        bool isUpdated = false;
        // Keep making new food until generating a valid spot
        while (gameBoard.at(newLocation.y).at(newLocation.x) == 'O')
        {
            isUpdated = true;
            playerFood.GenerateNewFood(GetGameBoundaries());
            newLocation = playerFood.location;
        }
        if (isUpdated)
            gameBoard.at(newLocation.y).at(newLocation.x) = 'X';
        return;
    }

    void GameEngine::PrepareGameBoard(void)
    {
        gameBoard.clear();
        sf::Vector2f boardDimensions = GetGameBoundaries();
        gameBoard.resize(boardDimensions.y, std::vector<char> (boardDimensions.x, ' '));
        player.headLocation.x = 4;
        player.headLocation.y = 5;
        char* locationState = &gameBoard.at(player.headLocation.y).at(player.headLocation.x);
        player.body.push(locationState);
        *player.body.front() = 'O';
        playerFood.location.x = 2;
        playerFood.location.y = 2;
        playerFood.food = &gameBoard.at(2).at(2);
        *playerFood.food = 'X';
        return;
    }

    void GameEngine::UpdatePlayerSpeed(void)
    {
        switch (GetPlayerInput()) {
            case kUp:
                player.speed.x = 0;
                player.speed.y = -1;
                break;
            case kLeft:
                player.speed.x = -1;
                player.speed.y = 0;
                break;
            case kRight:
                player.speed.x = 1;
                player.speed.y = 0;
                break;
            case kDown:
                player.speed.x = 0;
                player.speed.y = 1;
                break;
            default:
                break;
        }
    }
}
