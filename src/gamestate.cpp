// GameState.cpp
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

    void GameEngine::SetGameSettings(int argc, char* argv[])
    {
        std::string convertedString;
        for (int i = 0; i < argc; i++)
        {
            convertedString = argv[i];
            if (convertedString == "--no-sfml")
                useSFML = false;
        }
    }

    void GameEngine::StartGame()
    {
        ApplySettings();
        ResetGameBoard();
        graphics->StartGameWindow();
        GameLoop();
        return;
    }

    void GameEngine::ApplySettings(void)
    {
        if (useSFML)
            graphics.reset(new SFML());
        else
            graphics.reset(new CommandLine());
        return;
    }

    // TODO: Reimplement for DisplayInterface
    void GameEngine::DisplayEndScreen(void)
    {
        graphics->DisplayEndScreen();
        return;
    }
    
    void GameEngine::GameLoop(void)
    {
        sf::Vector2f newHeadPosition;
        while (graphics->IsOpen())
        {
            // player.UpdateDirection(playerInput.GetPlayerInput());
            // newHeadPosition = player.Move();
            // if (playerFood.GetFoodLocation() != newHeadPosition)
            //     player.Pop();
            // PlaceNewSnakePart(newHeadPosition);
            graphics->DisplayGameState(&gameBoard);
            // if (isGameOver)
            //     PlayerWantsToContinue();
        }
        return;
    }

    sf::Vector2f GameEngine::GetGameBoundaries(void)
    {
        return graphics->gameBoundaries;
    }

    void GameEngine::PlaceNewSnakePart(sf::Vector2f location)
    {
        char locationState;
        try 
        {
            locationState = gameBoard.at(location.y).at(location.x);
            if (locationState == 'O')
                isGameOver = true; // Game should end (Snake touching snake)
            if (locationState == ' ')
                player.Pop(); // Snake shouldn't extend
            gameBoard.at(location.y).at(location.x) = 'O'; 
        } catch (const std::out_of_range& error) {
            isGameOver = true; // Snake ran into edge
            return;
        }
        return;
    }

    void GameEngine::PlayerWantsToContinue(void)
    {
       graphics->CheckContinue();
       return;
    }

    // Generates new food until not colliding with player
    void GameEngine::RegenerateFood(void)
    {
        sf::Vector2f newLocation = playerFood.GetFoodLocation();
        bool isUpdated = false;
        // Keep making new food until generating a valid spot
        while (gameBoard.at(newLocation.y).at(newLocation.x) == 'O')
        {
            isUpdated = true;
            playerFood.GenerateNewFood(GetGameBoundaries());
            newLocation = playerFood.GetFoodLocation();
        }
        if (isUpdated)
            gameBoard.at(newLocation.y).at(newLocation.x) = 'X';
        return;
    }

    void GameEngine::ResetGameBoard(void)
    {
        gameBoard.clear();
        sf::Vector2f boardDimensions = GetGameBoundaries();
        std::vector<char> tempBoard;
        tempBoard.resize(boardDimensions.x, ' ');
        gameBoard.resize(boardDimensions.y, tempBoard);
        PlaceNewSnakePart(player.Reset());
        // playerFood.GenerateNewFood(boardDimensions);
        // sf::Vector2f foodStartLocation = playerFood.GetFoodLocation();
        // gameBoard.at(foodStartLocation.y).at(foodStartLocation.x) = 'X';
        // return;
    }
}
