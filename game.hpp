#ifndef GAME_H
#define GAME_H

#include "Grid.hpp"
#include <string>

class Game {
private:
    Grid board;
    int rows, cols, mines;
    bool gameOver = false;
    bool isQuit;
    bool isInvalid;
    bool isOpen;

public:
    Game();
    Game(int r, int c, int m);
    void run();
    bool processInput();
    bool isWin() const;
    void difChoice();
    bool playAgain();
};

#endif