#ifndef Cell_H
#define Cell_H

#include <iostream>
using namespace std;

class Cell {
private:
    bool open; //cell open?
    bool mine; //is the cell a mine?   
    int minesNearby; //how many adjacent mines
protected:
public:
    Cell(); //default constructor

    //getters
    const bool isOpen() const { return open; }
    const bool isMine() const { return mine; }
    int getNearby() { return minesNearby; }

    //setters
    void setOpen(bool b) { this->open = b; }
    void setMine(bool b) { this->mine = b; }

    //functions
    char display(); //returns a char to be printed
    void incMine(); //increments minesNearby

    ~Cell() {};
};


#endif //Cell_H