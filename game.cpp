#include "game.hpp"
#include <iostream>
#include <cctype>

using namespace std;

Game::Game(int r, int c, int m) : rows(r), cols(c), mines(m), board(r, c), gameOver(false) {
    board.putMines(mines);
}

void Game::run() {
    while (!gameOver) {
        board.print();
        if (!processInput()) {
            board.print();
            cout << " You hit a mine. Game Over!\n";
            break;
        }
        if (isWin()) {
            board.print();
            cout << " You won! All safe cells revealed.\n";
            break;
        }
    }
}

bool Game::processInput() {
    string input;
    cout << "Enter cell (e.g., A5): ";
    cin >> input;

    if (input.length() < 2) return true;

    char colChar = toupper(input[0]);
    int col = colChar - 'A';
    int row = atoi(input.substr(1).c_str());

    if (col < 0 || col >= cols || row < 0 || row >= rows) {
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
