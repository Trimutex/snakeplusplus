#ifndef DISPLAY_H
#define DISPLAY_H

#include <SFML/Graphics.hpp>

class DisplayInterface
{
public:
    sf::Vector2f gameBoundaries;
    DisplayInterface(void);
    bool IsOpen(void);
protected:
    bool isGameStillRunning;
    virtual void DisplayGameState(void) = 0;
    virtual void DisplayEndScreen(void) = 0;
    virtual void StartGame(void) = 0;
private:
    ;
};

class CommandLine : public DisplayInterface
{
public:
    CommandLine(void);
    void DisplayGameState(void);
    void DisplayEndScreen(void);
    void StartGame(void);
protected:
    ;
private:
    const int kGridSize = 25;
};

class SFML : public DisplayInterface
{
public:
    SFML(void);
    void DisplayGameState(void);
    void DisplayEndScreen(void);
    void StartGame(void);
    void UpdateResolution(sf::Vector2i newResolution);
protected:
    ;
private:
    sf::Time delay;
    sf::RenderWindow gameWindow;
    sf::VideoMode gameVideoSettings;
};

#endif
