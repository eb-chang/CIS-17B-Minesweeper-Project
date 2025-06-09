#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
//#include "myHeader.h"
#include "game.hpp"
#include "Record.hpp"
#include "Grid.hpp"
#include "User.hpp"
using namespace std;

int main() {

    //set random seed
    srand(static_cast<unsigned int>(time(0)));

    //set i/o file
    string filename = "bin_example.bin"; // change filename here if needed

    //load user?
    Record minesweeperRecord;
    minesweeperRecord.loadFile( filename ); // load user data
    
    User player = minesweeperRecord.login();
    minesweeperRecord.openAdminMenu(player); // opens the admin menu if "player" is an admin

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

    //game.difChoice();
    cout << "Starting the game..." << endl;
    game.run(player); // run the game with the logged-in user.
    cout << "W =" << player.getWins() << endl;
    cout << "L =" << player.getLosses() << endl;

    //display & record scoreboard

    // update user in record
    minesweeperRecord.updateUserScore(player);

    //write out data
    minesweeperRecord.saveFile(filename);

    //exit the program
    return 0;
}