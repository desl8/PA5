#ifndef EMPTYCELL_H
#define EMPTYCELL_H

#include "cell.h"

class EmptyCell : public Cell {
    public:
        EmptyCell();
        EmptyCell(bool, char, bool);
        EmptyCell(const EmptyCell&);
        void display();
        bool uncover(int*);
};
#endif