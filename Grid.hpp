#ifndef Grid_H
#define Grid_H

#include "Cell.hpp"

class Grid {
protected:
    int rows;
    int cols;
    int nMines;
private:

    Cell** board; //2d array of Cell objects
protected:
public:
    Grid();
    Grid(int, int);

    void setGrid(int, int);
    void putMines(int);
    void print();
    void header();
    
    void setRows(int x) { rows =x; }
    void setCols(int x) {  cols =x; }
    void setNumMines(int x) { nMines = x; }
    bool reveal(int, int); //new method added

    const Cell& getCell(int, int) const;

    ~Grid(); //destructor
};

#endif //Grid_H