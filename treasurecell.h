#ifndef TREASURECELL_H
#define TREASURECELL_H

#include "cell.h"

class TreasureCell : public Cell {
    public:
        TreasureCell();
        TreasureCell(bool, char, bool);
        TreasureCell(const TreasureCell&);
        void display();
        bool uncover(int*);
};
#endif