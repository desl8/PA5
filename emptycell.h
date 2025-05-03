#ifndef EMPTYCELL_H
#define EMPTYCELL_H

#include "cell.h"

class EmptyCell : public Cell {
    public:
        EmptyCell();
        EmptyCell(bool, char, bool);
        EmptyCell(const EmptyCell&);
        std::ostream& display(std::ostream&);
        bool uncover(int*);
};
#endif