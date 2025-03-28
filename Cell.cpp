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
        c = '1';
    }

    /* todo: add mines functionality

    if (this->hasMine == true)
    {
        //could put a gameover here or something
        c = '1';
    }

    if (this->isOpen == false)
        c = '?';
    */
    return c;
}
