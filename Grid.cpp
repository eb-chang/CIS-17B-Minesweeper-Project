#include <iostream>
#include <iomanip>

#include "Grid.hpp"

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

    this->board = new Cell*[this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        this->board[i] = new Cell[this->cols];
    }
}

void Grid::putMines(int n)
{
    this->nMines = n;
    
    for(int i = 0; i < this->nMines; i++){
        int r = rand() % (rows - 1);
        int c = rand() % (cols - 1);
        if(this->board[r][c].isMine() == true) i--;
            else this->board[r][c].setMine(true);
    }
}

void Grid::print()
{
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            cout << this->board[i][j].display();
        }
        cout << endl;
    }
}

Grid::~Grid()
{
    //delete all the rows
    for (int i = 0; i < this->rows; i++)
    {
        delete []this->board[i];
    }

    //delete the board
    delete [] this->board;
}
