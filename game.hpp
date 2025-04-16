#ifndef GAME_H
#define GAME_H

#include "grid.hpp"
#include <string>

class Game {
private:
    Grid board;
    int rows, cols, mines;
    bool gameOver;
    bool isQuit;

public:
    Game();
    Game(int r, int c, int m);
    void run();
    bool processInput();
    bool isWin() const;
    void difChoice();
};

#endif