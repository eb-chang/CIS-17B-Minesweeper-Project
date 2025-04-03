#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include "game.hpp"

#include "Grid.hpp"

using namespace std;


int main() {

    //set random seed
    srand(static_cast<unsigned int>(time(0)));

    //declare vars
    int r, c, m;//rows, cols, mines

    //load user?

    /*
    prompt user for difficulty

    beginner - 8x8 (or 9x9) w/ 10 mines
    intermediate - 16x16 w/ 40 mines
    expert - 16x30 w/ 99 mines
    */
    r = 9;
    c = 9;
    m = 10;

    //create and run game
    Game game(r, c, m); // Easy 9x9 with 10 mines
    game.run();

    //display & record scoreboard

    //another game?

    //exit the program
    return 0;
}