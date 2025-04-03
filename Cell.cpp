#include <iostream>
#include <iomanip>

#include "Cell.hpp"
using namespace std;

Cell::Cell()
{
    this->open = false;
    this->mine = false;
    this->minesNearby = 0;
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