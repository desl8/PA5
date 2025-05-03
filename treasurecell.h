#ifndef TREASURECELL_H
#define TREASURECELL_H

#include "cell.h"

class TreasureCell : public Cell {
    public:
        TreasureCell();
        TreasureCell(bool, char, bool);
        TreasureCell(const TreasureCell&);
        std::ostream& display(std::ostream&);
        bool uncover(int*);
};
#endif