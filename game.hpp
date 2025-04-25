#ifndef GAME_H
#define GAME_H

#include "Grid.hpp"
#include <string>

class Game: public Grid {
private:
    
 
    bool gameOver = false;
    bool isQuit;
    bool isInvalid;
    bool isOpen;

public:
    Game();
    void run();
    bool playAgain();
    bool processInput();
    bool isWin() const;
    void difChoice();
    
};

#endif