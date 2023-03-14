#ifndef DISPLAY_H
#define DISPLAY_H

class DisplayInterface
{
public:
    DisplayInterface(void);
protected:
    virtual void DisplayGameState(void) = 0;
private:
    ;
};

class CommandLine : public DisplayInterface
{
public:
    CommandLine(void) = default;
    void DisplayGameState(void);
protected:
    ;
private:
    ;
};

class GameWindow : public DisplayInterface
{
public:
    GameWindow(void) = default;
    void DisplayGameState(void);
protected:
    ;
private:
    ;
};

#endif