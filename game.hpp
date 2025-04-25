#ifndef GAME_H
#define GAME_H

#include "Grid.hpp"
#include "User.hpp"
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
    void run(User player);
    bool playAgain();
    bool processInput();
    bool isWin() const;
    void difChoice();
};

#endif