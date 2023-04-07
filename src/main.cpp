#include "gamestate.hpp"

int main(int argc, char *argv[])
{
    snakeplusplus::GameEngine game;
    game.SetGameSettings(argc, argv);
    game.StartGame();
}
