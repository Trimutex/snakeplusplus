// GameState.cpp
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <stdexcept>
#include <string>
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
        sf::Vector2f newHeadPosition;
        while (graphics.IsOpen())
        {
            UpdatePlayerSpeed();
            PlaceNewSnakePart(MovePlayer());
            graphics.DisplayGameState(&gameBoard);
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
        char locationState;
        try 
        {
            locationState = gameBoard.at(location.y).at(location.x);
            if (locationState == 'O')
                isGameOver = true; // Game should end (Snake touching snake)
            if (playerFood.location != location)
                player.Pop();
            gameBoard.at(location.y).at(location.x) = 'O'; 
        } catch (const std::out_of_range& error) {
            isGameOver = true; // Snake ran into edge
            return;
        }
        return;
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
        std::vector<char> tempBoard;
        tempBoard.resize(boardDimensions.x, ' ');
        gameBoard.resize(boardDimensions.y, tempBoard);
        sf::Vector2f playerLocation(4,5);
        char* headLocation = &gameBoard.at(playerLocation.y).at(playerLocation.x);
        *headLocation = 'O';
        player.body.push(std::shared_ptr<char>(headLocation));
        sf::Vector2f foodLocation(2,2); 
        gameBoard.at(foodLocation.y).at(foodLocation.x) = 'X';
        return;
    }

    void GameEngine::UpdatePlayerSpeed(void)
    {
        PlayerDirection input = controls.GetPlayerInput();
        switch (input) {
            case kUp:
                player.speed.x = 0;
                player.speed.y = 1;
            case kLeft:
                player.speed.x = -1;
                player.speed.y = 0;
            case kRight:
                player.speed.x = 1;
                player.speed.y = 0;
            case kDown:
                player.speed.x = 0;
                player.speed.y = -1;
            default:
                break;
        }
    }
}
