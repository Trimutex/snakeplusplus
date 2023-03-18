#include "gamestate.h"

int main(int argc, char *argv[])
{
    GameState game;
    game.SetGameSettings(argc, argv);
    game.StartGame();
}
