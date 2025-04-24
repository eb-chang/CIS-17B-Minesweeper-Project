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
    cout << " ___ ___  ____  ____     ___  _____ __    __    ___    ___  ____   ___  ____" << endl; 
    cout << "|   |   ||    ||    \\   /  _]/ ___/|  |__|  |  /  _]  /  _]|    \\ /  _]|    \\" << endl;
    cout << "| _   _ | |  | |  _  | /  [_(   \\_ |  |  |  | /  [_  /  [_ |  o  )  [_ |  D  )" << endl;
    cout << "|  \\_/  | |  | |  |  ||    _]\\__  ||  |  |  ||    _]|    _]|   _/    _]|    /" << endl; 
    cout << "|   |   | |  | |  |  ||   [_ /  \\ ||  `  '  ||   [_ |   [_ |  | |   [_ |    \\" << endl;
    cout <<  "|   |   | |  | |  |  ||     |\\    | \\      / |     ||     ||  | |     ||  .  \\" << endl;
    cout << "|___|___||____||__|__||_____| \\___|  \\_/\\_/  |_____||_____||__| |_____||__|\\_|" << endl << endl;
                                                                                 
   
    cout << "Before you embark on this dangerous task,"
         << " please choose a difficulty level from the menu below.\n";

<<<<<<< HEAD
    //game.difChoice();
    cout << "Starting the game..." << endl;
=======
    //difficulty select
    game.difChoice();

    //run the game
>>>>>>> a89618b906d5dc8d46a9f89f5448d868b1d28c77
    game.run();

    
    //display & record scoreboard

    //another game?

    //exit the program
    return 0;
}