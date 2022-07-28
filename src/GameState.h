// GameState.h
#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState
{
private:
    int videoSizeHorizontal;
    int videoSizeVertical;
    sf::RenderWindow window;
public:
    GameState();
    GameState(int newHorizontal, int newVertical);
};

#endif
