#include "Grid.hpp"


#include <iostream>
#include <iomanip>
#include <cstdlib>



using namespace std;

Grid::Grid()
{
    this->rows = 0;
    this->cols = 0;
    this->board = nullptr;
}

Grid::Grid(int r, int c)
{
    this->rows = r;
    this->cols = c;

    this->board = new Cell * [this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        this->board[i] = new Cell[this->cols];
    }
}

//void Grid::putMines(int n)
//{
//    this->nMines = n;
//    int r, c;
//    int num_of_placed_mine = 0;
//
//    //this is essentially brian's function modded to work with objects
//    for (int i = 0; i < this->nMines; i++) {
//        r = rand() % this->rows;
//        c = rand() % this->cols;
//        if (this->board[r][c].isMine() == true) i--;
//        else
//        {
//            this->board[r][c].setMine(true);
//
//            //todo: increment minesNearby for surrounding mines
//
//        }
//    }
//}

void Grid::putMines(int n) {
    nMines = n;
    int num_of_placed_mine = 0;
    while (num_of_placed_mine < nMines) {
        int r = rand() % rows;
        int c = rand() % cols;
        if (board[r][c].isMine()) continue;

        board[r][c].setMine(true);
        num_of_placed_mine++;

        for (int dr = -1; dr <= 1; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !(dr == 0 && dc == 0))
                    board[nr][nc].incMine();
            }
        }
    }
}

void Grid::print()
{
    //header
    this->header();

    //grid
    for (int i = 0; i < this->rows; i++)
    {
        cout << setw(2) << i << "| ";
        for (int j = 0; j < this->cols; j++)
        {
            cout << setw(2) << this->board[i][j].display();
        }
        cout << " |" << endl;
    }

    //footer?
    cout << "  ";
    for (int i = 0; i < this->cols; i++)
        cout << "--";
    cout << "----" << endl;
}

void Grid::header()
{
    cout << endl << "    ";
    for (int i = 0; i < this->cols; i++)
        cout << setw(2) << static_cast<char>(i + 65);
    cout << endl << "  ";
    for (int i = 0; i < this->cols; i++)
        cout << "--";
    cout << "---- " << endl;

}


bool Grid::reveal(int r, int c) {

    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return true; // out of bounds = skip

    if (board[r][c].isOpen()) return true;

    board[r][c].setOpen(true);

    if (board[r][c].isMine()) return false; // Game over

    if (board[r][c].getNearby() == 0) {
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dr != 0 || dc != 0)
                    reveal(r + dr, c + dc);
            }
        }
    }

    return true;

}

const Cell& Grid::getCell(int r, int c)const {
    return board[r][c];
}

Grid::~Grid()
{
    //delete all the rows
    for (int i = 0; i < this->rows; i++)
    {
        delete[]this->board[i];
    }

    //delete the board
    delete[] this->board;
}

