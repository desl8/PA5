#ifndef EMPTYCELL_H
#define EMPTYCELL_H

#include "cell.h"

class EmptyCell : public Cell {
    public:
        EmptyCell();
        EmptyCell(bool, char, bool);
        EmptyCell(const EmptyCell&);
        bool uncover(int*);
};
#endif