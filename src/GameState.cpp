// GameState.cpp
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "Snake.h"
#include "GameState.h"

GameState::GameState()
{
    delay = sf::milliseconds(100);
    gameVideoSettings = sf::VideoMode(1024, 725);
    gameWindow.create(gameVideoSettings, "SnakePlusPlus");
    return;
}

GameState::GameState(int maxHorizontal, int maxVertical)
{
    delay = sf::milliseconds(100);
    gameVideoSettings = sf::VideoMode(maxHorizontal, maxVertical);
    gameWindow.create(gameVideoSettings, "SnakePlusPlus");
    return;
}

void GameState::StartGame()
{
    gameWindow.create(gameVideoSettings, "SnakePlusPlus");
    Snake player(sf::Vector2f(kGridSize,kGridSize));
    SnakeFood playerFood(sf::Vector2f(kGridSize,kGridSize));
    RunGameLoop();
}

sf::Vector2f GameState::GetGameBoundaries(void)
{
    sf::Vector2f boundaries;
    boundaries.x = gameVideoSettings.width;
    boundaries.y = gameVideoSettings.height;
    return boundaries;
}

// Generates new food until not colliding with player
void GameState::RegenerateFood(void)
{
    // Keep making new food until generating a valid spot
    while (player.IsTouchingObject(playerFood.GetFoodObject()))
        playerFood.GenerateNewFood(GetGameBoundaries());
    return;
}

void GameState::RunGameLoop(void)
{
    sf::Event event;
    while (gameWindow.isOpen())
    {
        while (gameWindow.pollEvent(event))
        {
            if ((event.type == sf::Event::Closed) || 
                (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                gameWindow.close();
        }
        player.CheckDirection();
        player.MoveSnake(playerFood, gameVideoSettings);
        RegenerateFood();
        RenderWindow();
        sf::sleep(delay);
    }
}

void GameState::RenderWindow(void)
{
    gameWindow.clear();
    player.DisplaySnake(gameWindow);
    gameWindow.draw(playerFood.GetFoodObject());
    gameWindow.display();
}
