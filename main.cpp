#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include "game.hpp"

#include "Grid.hpp"

using namespace std;


int main() {

    /*
        this part of main() was originally written by Brian and generates a simple minesweeper grid
        where 0 = blank and 1 = mine
    */
    srand(static_cast<unsigned int>(time(0)));

    //config here
   // 16x16 with 40 mines is "intermediate" difficulty
 /*   const int rows = 16;
    const int cols = 16;
    int minesAmount = 40;*/

    //int gridMines[rows][cols];
    //for (int i = 0; i < rows; i++) {
    //    for (int j = 0; j < cols; j++) {
    //        gridMines[i][j] = 0;
    //    }
    //}

    //for (int i = 0; i < minesAmount; i++) {
    //    int r = rand() % (rows - 1);
    //    int c = rand() % (cols - 1);
    //    if (gridMines[r][c] == 1) i--;
    //    else gridMines[r][c] = 1;
    //}

    //for (int i = 0; i < rows; i++) {
    //    for (int j = 0; j < cols; j++) {
    //        cout << gridMines[i][j];
    //    }
    //    cout << endl;
    //}

   /* cout << "here is an object - oriented approach using a modified version of brian's algorithm" << endl;
    cout << endl;*/
    //Grid board(rows, cols);
    //board.putMines(minesAmount);
    //board.print();

    Game game(9, 9, 10); // Easy 9x9 with 10 mines
    game.run();



    return 0;
}