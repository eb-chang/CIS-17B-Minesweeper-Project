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

        void putMines(int);
        void print();
        void header();

        ~Grid(); //destructor
};

#endif //Grid_H