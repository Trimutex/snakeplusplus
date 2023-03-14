// GameState.cpp
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "common.h"
#include "gamestate.h"

GameState::GameState()
{
    delay = sf::milliseconds(75);
    gameVideoSettings = sf::VideoMode(1025, 725);
    gameWindow.create(gameVideoSettings, "SnakePlusPlus");
    if (useSFML)
        graphics.reset(new GameWindow());
    else
        graphics.reset(new CommandLine());
    
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
    RunGameLoop();
    return;
}

void GameState::DisplayEndScreen(void)
{
    gameWindow.clear();
    sf::Vector2f textPosition(GetGameBoundaries());
    textPosition.x = textPosition.x / 2;
    textPosition.y = textPosition.y / 2;
    sf::Text gameOverText;
    gameOverText.setString("Game Over");
    gameOverText.setCharacterSize(30);
    gameOverText.setPosition(textPosition);
    gameWindow.draw(gameOverText);
    gameWindow.display();
    if (!PlayerWantsToContinue())
        return;
    player = Snake();
    playerFood.GenerateNewFood(GetGameBoundaries());
    gameWindow.clear();
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

bool GameState::PlayerWantsToContinue(void)
{
    sf::Event event;
    while (true)
    {
        while (gameWindow.pollEvent(event))
        {
            if ((event.type == sf::Event::Closed) || 
                (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                gameWindow.close();
            return false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            return true;
        sf::sleep(delay);
    }
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
    if (player.gameFinished)
        DisplayEndScreen();
    return;
}
