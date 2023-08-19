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
        snakeplusplus::InitializeGenerator();
        return;
    }

    void GameEngine::Start()
    {
        PrepareGameBoard();
        graphics.StartGameWindow();
        Loop();
        return;
    }

    void GameEngine::Reset()
    {
        graphics.CheckContinue();
        player.Reset();
        PrepareGameBoard();
        isGameOver = 0;
        return;
    }

    void GameEngine::Loop(void)
    {
        while (graphics.IsOpen())
        {
            if (isGameOver) {Reset();}
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
            if (*locationState == 'O' && (player.body.size() > 1))
                isGameOver = true; // Game should end (Snake touching snake)
            *locationState = 'O';
            player.body.push(locationState);
            player.headLocation = location;
            if (playerFood.location != location)
                player.Pop();
        } catch (const std::out_of_range& error) {
            isGameOver = true; // Snake ran into edge
        }
        return;
    }

    // Generates new food until not colliding with player
    void GameEngine::RegenerateFood(void)
    {
        sf::Vector2f newLocation = playerFood.location;
        bool isUpdated = false;
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
        // Snake setup
        {
            player.headLocation.x = GenerateRandomNumber(boardDimensions.x);
            player.headLocation.y = GenerateRandomNumber(boardDimensions.y);
            char* locationState = &gameBoard.at(player.headLocation.y).at(player.headLocation.x);
            player.body.push(locationState);
            *locationState = 'O';
        }
        // Food setup
        {
            playerFood.GenerateNewFood(boardDimensions);
            sf::Vector2f newLocation = playerFood.location;
            gameBoard.at(newLocation.y).at(newLocation.x) = 'X';
        }
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
        return;
    }
}
