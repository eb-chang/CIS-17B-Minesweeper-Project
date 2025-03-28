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
    char c = '0';

    if (this->mine == true)
    {
        c = 'X';
    }else{
        c = this->minesNearby + 48;//ascii
    }

    /*    
        if (this->open == false)
        c = '?';
    */
    return c;
}

void Cell::incMine()
{
    this->minesNearby += 1;
}
