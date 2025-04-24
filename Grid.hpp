#ifndef Grid_H
#define Grid_H

#include "Cell.hpp"

class Grid {
private:
    int rows;
    int cols;
    int nMines;
    Cell** board; //2d array of Cell objects
protected:
public:
    Grid();
    Grid(int, int);

    void setGrid(int, int);
    void putMines(int);
    void print();
    void header();
    

    bool reveal(int, int); //new method added

    const Cell& getCell(int, int) const;

    ~Grid(); //destructor
};

#endif //Grid_H