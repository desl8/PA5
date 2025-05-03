#ifndef TRAPCELL_H
#define TRAPCELL_H

#include "cell.h"

class TrapCell : public Cell {
    public:
        TrapCell();
        TrapCell(bool, char, bool);
        TrapCell(const TrapCell&);
        void display();
        bool uncover(int*);
};
#endif