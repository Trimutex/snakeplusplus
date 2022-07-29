// GameState.h
#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState
{
private:
public:
    unsigned int videoSizeHorizontal;
    unsigned int videoSizeVertical;
    // sf::RenderWindow window;
    GameState();
    GameState(int newHorizontal, int newVertical);
    // sf::Vector2f GetGameBoundaries();
};

#endif
