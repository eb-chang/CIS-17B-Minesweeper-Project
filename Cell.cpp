#include <iostream>
#include <iomanip>

#include "Cell.hpp"
using namespace std;

// default constructor definition
Cell::Cell() {
    open = false;
    mine = false;
    flag = false;
    minesNearby = 0;
}

// copy constructor
Cell::Cell(bool cellOpen, bool cellMine, bool cellFlag, int cellNearby) {
    open = cellOpen;
    mine = cellMine;
    flag = cellFlag;
    minesNearby = cellNearby;
}

char Cell::display()
{


    if (!open)
    {
        return '?';
    }
    if (mine) {

        return 'X';//ascii
    }


    return '0' + minesNearby;
}

void Cell::incMine()
{
    this->minesNearby += 1;
}