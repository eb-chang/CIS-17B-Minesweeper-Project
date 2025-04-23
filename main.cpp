#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
//#include "myHeader.h"
#include "game.hpp"

#include "Grid.hpp"

using namespace std;

int main() {

    //set random seed
    srand(static_cast<unsigned int>(time(0)));


    //load user?


    //create and run game
    Game game; 
    
    //Welcome player to the game
    cout << "Welcome to Minesweeper!\n"
    << "Before you embark on this dangerous task,"
    << " please choose a difficulty level from the menu below.\n";

    //difficulty select
    game.difChoice();

    //run the game
    cout << "Starting the game..." << endl;
    game.run();

    
    //display & record scoreboard

    //another game?

    //exit the program
    return 0;
}