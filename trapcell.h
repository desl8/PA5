#include "cell.h"

class TrapCell : public Cell {
    public:
        TrapCell();
        TrapCell(bool, char, bool);
        TrapCell(const TrapCell&);
        bool uncover(int*);
};