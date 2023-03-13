// GameState.cpp
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "Common.h"
#include "Snake.h"
#include "GameState.h"

GameState::GameState()
{
    delay = sf::milliseconds(75);
    gameVideoSettings = sf::VideoMode(1025, 725);
    gameWindow.create(gameVideoSettings, "SnakePlusPlus");
    return;
}

GameState::GameState(int maxHorizontal, int maxVertical)
{
    delay = sf::milliseconds(75);
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
    return;
}

sf::Vector2f GameState::GetGameBoundaries(void)
{
    sf::Vector2f boundaries;
    boundaries.x = gameVideoSettings.width;
    boundaries.y = gameVideoSettings.height;
    return boundaries;
}

void GameState::GetKeyboardInput(void)
{
    sf::Event event;
    while (gameWindow.pollEvent(event))
    {
        if ((event.type == sf::Event::Closed) || 
            (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
            gameWindow.close();
    }
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
    while (gameWindow.isOpen())
    {
        GetKeyboardInput();
        player.MoveSnake(&playerFood);
        RegenerateFood();
        RenderWindow();
        sf::sleep(delay);
    }
    return;
}

void GameState::RenderWindow(void)
{
    gameWindow.clear();
    player.DisplaySnake(gameWindow);
    gameWindow.draw(playerFood.GetFoodObject());
    gameWindow.display();
    return;
}
