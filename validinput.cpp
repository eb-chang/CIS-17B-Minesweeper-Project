/*
Author: Sunny and Bryan
Purpose: To get valid input from the user when selecting a tile
*/

//system libraries
#include "myHeader.h"

//user libraries

//global constants not variable
//science, math, conversion, dimension

//function prototypes

//execution begins here at main
void validinput() {

    //set random number seed

    //declare variables
    int choice; //To hold a menu choice
    char row; //To hold a row input
    int col; //To hold a column input

    //initialize variables
    //Welcome player to the game
    cout << "Welcome to Minesweeper!\n"
         << "Before you embark on this dangerous task,"
         << " please choose a difficulty level from the menu below.\n";
    
    //Display the menu and get the user's choice     
    cout << "\n\t\tGame Difficulty Level\n\n"
         << "1. Beginner (Barely break a sweat)\n"
         << "2. Intermediate (Sweat a little here and there)\n"
         << "3. Expert (Drenched in sweat)\n"
         << "4. Quit (No shame in bailing out, ok maybe a little)\n";
    cin >> choice;

    //Validate the menu selection
    while ( choice < 1 || choice > 4 ){
        cout << "\nPlease enter a valid menu choice: ";
        cin >> choice;
    }     

    //Have to throw in a statement to test the validity if a blank tile is selected.
    //Not sure how to test/implement that unless the tiles are static?

    //Need to set up a do/while loop that allows the user to select a row and tile
    //but that ends on two occasions:
    //1. Selecting a tile which has a bomb
    //2. User wins the game
    
    switch ( choice ){
        case 1: //Beginner grid of 8 rows by 10 columns
        cout << "Please input a row (A-H) and column(0-9)\n";
        cin >> row >> col;
        while ( row < 'A' || row > 'H' ){
            cout << "Please enter a valid row (A-H): ";
            cin >> row;
        }
        while ( col < 1 || col > 9 ){
            cout << "Please enter a valid column (1-9): ";
            cin >> col;
        }
        break;
        case 2: //Intermediate grid of 16 rows by 16 columns
        cout << "Please input a row (A-P) and column(0-15)\n";
        cin >> row >> col;
        while ( row < 'A' || row > 'P' ){
            cout << "Please enter a valid row (A-P): ";
            cin >> row;
        }
        while ( col < 1 || col > 15 ){
            cout << "Please enter a valid column (1-15): ";
            cin >> col;
        }
        break;
        case 3: //Expert grid of 20 rows by 24 columns
        cout << "Please input a row (A-K) and column(0-23)\n";
        cin >> row >> col;
        while ( row < 'A' || row > 'K' ){
            cout << "Please enter a valid row (A-P): ";
            cin >> row;
        }
        while ( col < 1 || col > 15 ){
            cout << "Please enter a valid column (1-15): ";
            cin >> col;
        }
    }
}