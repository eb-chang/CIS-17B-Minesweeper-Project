#include "game.hpp"
#include <iostream>
#include <cctype>

using namespace std;

Game::Game(){

}

Game::Game(int r, int c, int m) : rows(r), cols(c), mines(m), board(r, c), gameOver(false) {
    board.putMines(mines);
}

void Game::run() {
    while (!gameOver) {
        board.print();
        if (!processInput()) {
            if(!isQuit){
                board.print();
                cout << " You hit a mine. Game Over!\n";
                gameOver = true;
            }
            else{
                gameOver = true;
            }
        }
        if (isWin()) {
            board.print();
            cout << " You won! All safe cells revealed.\n";
            gameOver = true;
        }
    }
}

bool Game::processInput() {
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
        cout << "Invalid input.\n";
        return true;
    }

    return board.reveal(row, col);
}

bool Game::isWin() const {
    int safeCells = (rows * cols) - mines;
    int revealed = 0;
    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c)
            if (board.getCell(r, c).isOpen() && !board.getCell(r, c).isMine())
                revealed++;
    return revealed == safeCells;
}

void Game::difChoice(){
    int choice;
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

    switch(choice){
        case 1: 
            rows = 9;
            cols = 9;
            mines = 10;
            gameOver = false;
            break;
        case 2: 
            this->rows = 16;
            this->cols = 16;
            this->mines = 40;
            gameOver = false;
            break; 
        case 3: 
            this->rows = 30;
            this->cols = 16;
            this->mines = 99;
            gameOver = false;
            break;
        case 4: 
            gameOver = true;
            cout << "Quitting" << endl;
    }
    
    board.setGrid(rows, cols);
    board.putMines(mines);
    
}
