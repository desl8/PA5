#include "cell.h"

class TreasureCell : public Cell {
    public:
        TreasureCell();
        TreasureCell(bool, char, bool);
        TreasureCell(const TreasureCell&);
        bool uncover(int*);
};