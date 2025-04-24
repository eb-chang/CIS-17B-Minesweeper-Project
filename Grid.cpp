#include "Grid.hpp"


#include <iostream>
#include <iomanip>
#include <cstdlib>



using namespace std;

//Default constructor
Grid::Grid()
{
    this->rows = 0;
    this->cols = 0;
    this->board = nullptr;
}

//Dynamically creates 2D Cell array object
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

/*******************************************
    Function setGrid.
    Dynamically creates 2D Cell array object
********************************************/
void Grid::setGrid(int rows, int cols){
    this->rows = rows;
    this->cols = cols;

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

/**********************************************
   Function putMines.
   Sets mines at random locations on the 
   grid and then increments the minecount 
   for the possible 8 locations around the bomb.
***********************************************/
void Grid::putMines(int n) {
    nMines = n;
    int num_of_placed_mine = 0;
    //sets mine at random location
    while (num_of_placed_mine < nMines) {
        int r = rand() % rows;
        int c = rand() % cols;
        if (board[r][c].isMine()) continue;

        board[r][c].setMine(true);
        num_of_placed_mine++;

        /* Mine is in location [i][j]

        [i-1][j-1]   [i-1][j]   [i-1][j+1]
        [i][j-1]     [i][j]     [i][j+1]
        [i+1][j-1]   [i+1][j]   [i+1][j+1]
        Increments the minecount around the mine
        */ 
        for (int dr = -1; dr <= 1; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                int nr = r + dr;
                int nc = c + dc;
                //Makes sure that the mine offsets are within range
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !(dr == 0 && dc == 0))
                    board[nr][nc].incMine();
            }
        }
    }
}

/***********************************
    Function print.
    Outputs the minesweeper board to
    the screen.
************************************/
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

/**************************************************
    Function header.
    Displays the letters that represent the columns
    for the minesweeper board.
***************************************************/
void Grid::header()
{
    //Outputs letters
    cout << endl << "    ";
    for (int i = 0; i < this->cols; i++)
        cout << setw(2) << static_cast<char>(i + 65);
    cout << endl << "  ";
    for (int i = 0; i < this->cols; i++)
        cout << "--";
    cout << "---- " << endl;

}

/******************************************
    Function reveal.
    Reveals cell that user clicks on.
    Also reveals all adjacent empty cells
    if user clicks on empty cell. 
*******************************************/
bool Grid::reveal(int r, int c) {

    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return true; // out of bounds = skip

    //If cell is already revealed, skip it
    if (board[r][c].isOpen()) return true;

    //Reveals cell
    board[r][c].setOpen(true);

    if (board[r][c].isMine()) return false; // Game over

    //Cell is empty (no mine, no mine count)
    if (board[r][c].getNearby() == 0) {
        //Loops through the 8 possible locations around tile
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dr != 0 || dc != 0) // Prevents the tile from revealing itself again
                    reveal(r + dr, c + dc);
            }
        }
    }

    return true;

}

/**********************************************
    Function getcell.
    returns current cell object from the board.
***********************************************/
const Cell& Grid::getCell(int r, int c)const {
    return board[r][c];
}

//Destructor
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