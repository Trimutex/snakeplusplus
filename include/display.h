#ifndef DISPLAY_H
#define DISPLAY_H

#include <SFML/Graphics.hpp>

const int kGridSize = 25;

class DisplayInterface
{
public:
    sf::Vector2f gameBoundaries;
    DisplayInterface(void);
    bool IsOpen(void);
    virtual void CheckContinue(void) = 0;
    virtual void DisplayGameState(std::vector< std::vector<char> >* gameBoard) = 0;
    virtual void DisplayEndScreen(void) = 0;
    virtual void StartGameWindow(void) = 0;
protected:
    bool isWindowAlive;
private:
    ;
};

class CommandLine : public DisplayInterface
{
public:
    CommandLine(void);
    void CheckContinue(void);
    void DisplayGameState(std::vector< std::vector<char> >* gameBoard);
    void DisplayEndScreen(void);
    void StartGameWindow(void);
protected:
    ;
private:
    ;
};

class SFML : public DisplayInterface
{
public:
    SFML(void);
    void CheckContinue(void);
    void DisplayGameState(std::vector< std::vector<char> >* gameBoard);
    void DisplayEndScreen(void);
    void StartGameWindow(void);
    void UpdateResolution(sf::Vector2i newResolution);
protected:
    ;
private:
    void CheckWindowEvents(void);
    void DrawEmpty(sf::Vector2f location);
    void DrawFood(sf::Vector2f location);
    void DrawSnake(sf::Vector2f location);
    sf::Time delay;
    sf::RenderWindow gameWindow;
    sf::VideoMode gameVideoSettings;
    sf::RectangleShape drawObject;
};

#endif
