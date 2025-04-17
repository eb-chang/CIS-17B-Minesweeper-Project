#ifndef CELL_H
#define CELL_H

#include <iostream>
using namespace std;

class Cell {
private:
    bool open; //cell open?
    bool mine; //is the cell a mine?   
    bool flag; //does cell have flag?
    int minesNearby; //how many adjacent mines

public:
    // constructors
    Cell();
    Cell(bool cellOpen, bool cellMine, bool cellFlag, int cellNearby);

    //getters
    const bool isOpen() const { return open; }
    const bool isMine() const { return mine; }
    const bool hasFlag() const { return flag; }
    int getNearby() { return minesNearby; }

    //setters
    // bool b represents the value for which the cell attribute will be assigned.
    void setOpen(bool b) { this->open = b; }
    void setMine(bool b) { this->mine = b; }
    void setFlag(bool b) { this->flag = b; }
    void setNearby(int);


    //functions
    char display(); //returns a char to be printed
    void incMine(); //increments minesNearby

    ~Cell() {};
};

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

#endif //CELL_H