#include "game.hpp"
#include "Grid.hpp"
#include "User.hpp"
#include <iostream>
#include <cctype>

using namespace std;

Game::Game(){
    cout << "GAME ON!" << endl;
}


void Game::run(User player) {
    bool playing = true;

    while (playing) {
        difChoice();
        if (gameOver) return; // Handle quitting from difChoice()

        start = time(0); // Set timer
        print();
        gameOver = false;

        while (!gameOver) {
            if (!processInput()) {
                if (!isQuit) {
                    print();
                    player.addLoss();
                    cout << " You hit a mine. Game Over!\n";
                } else {
                    cout << " You chose to quit.\n";
                }
                gameOver = true; // End current round
            } else if (isWin()) {
                print();
                cout << " You won! All safe cells revealed.\n";
                player.addWin();
                gameOver = true;
            } else if (isInvalid) {
                cout << "Invalid input.\n";
            } else if (isOpen) {
                cout << "Cell is already open.\n";
            } else {
                print();
            }

            end = time(0); // End timer
            timer(); //Display timer
        }

        // Ask if player wants to play again after game ends
        playing = !playAgain(); // if user chooses 1 (play again), keep looping
    }
}

bool Game::playAgain(){
    int choice;
    bool endGame = true;
    cout << "1. Play again" << endl;
    cout << "2. Quit" << endl; 
    cin >> choice;
    cin.ignore();
    switch(choice){
        case 1: //difChoice();
                endGame = false;
                break;
        case 2: endGame = true;
    }
    return endGame;
}

bool Game::processInput() {
    isQuit = false;
    isInvalid = false;
    isOpen = false;
    string input;
    cout << "Enter cell (e.g., A5) or '00' to quit the game: ";
    cin >> input;

    char colChar = toupper(input[0]);
    int col = colChar - 'A';
    int row = atoi(input.substr(1).c_str());

    if(input == "00"){
        cout << "\nQuit the game" << endl;
        isQuit = true;
        return false;
    }

    if (col < 0 || col >= cols || row < 0 || row >= rows || input.length() < 2 ||
        isalpha(input[1])) {
        //cout << "Invalid input.\n";
        isInvalid = true;
        return true;
    }

    if(getCell(row, col).isOpen()){
        isOpen = true;
        return true;
    }

    return reveal(row, col);
}

bool Game::isWin() const {
    int safeCells = (rows * cols) - nMines;
    int revealed = 0;
    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c)
            if (getCell(r, c).isOpen() && !getCell(r, c).isMine())
                revealed++;
    return revealed == safeCells;
}

void Game::difChoice(){
    isInvalid = true;
    char choice; // Changed to char instead of int

    //Display the menu and get the user's choice     
    cout << "\n\t\tGame Difficulty Level\n\n"
    << "1. Beginner (Barely break a sweat)\n"
    << "2. Intermediate (Sweat a little here and there)\n"
    << "3. Expert (Drenched in sweat)\n"
    << "4. Quit (No shame in bailing out, ok maybe a little)\n";

    cin.get(choice); //Only gets one char as input
    cin.ignore(1000, '\n'); //Ignore 1000 chars or until new line

   //Validate the menu selection
   while ( isInvalid )
   {
    switch(choice)
    {
        case '1': //selection 1
            isInvalid = false;
            rows=9;
            cols = 9;
            nMines =10;


            
            gameOver = false;
            break;
        case '2': // selection 2
            isInvalid = false;
            rows = 16;
            cols = 16;
            nMines = 40;

        ;
            gameOver = false;
            break; 
        case '3': //Selection 3
            isInvalid = false;
            rows = 30;
            cols = 16;
            nMines = 99;

           
            gameOver = false;
            break;
        case '4': //quit
            isInvalid = false;
            gameOver = true;
            cout << "Quitting" << endl;
            return; //Added return to fix infinite loop
            break;
        default: //Anything other than the main selections
            cout << "\nPlease enter a valid menu choice: ";
            cin.get(choice);
            cin.ignore(1000, '\n'); //Ignore 1000 chars or until new line
            break;
        }
    }
    setGrid(rows, cols);
    putMines(nMines);
}

void Game::timer()
{
    int totSec = end - start;
    int min = totSec / 60;
    int sec = totSec % 60;

    cout << "Time: ";
    //Format mins and secs if double digits
    //          over ten minutes     less than 10 minutes
    (min > 9) ? cout << min << ":" : cout << '0' << min << ":"; 
    //          over 10 seconds       less than 10 seconds
    (sec > 9) ? cout << sec << endl : cout << '0' << sec << endl;
}
