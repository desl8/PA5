#include "treasurecell.h"

TreasureCell::TreasureCell() : Cell() {
    symbol = '.';
}

TreasureCell::TreasureCell(bool u, char c, bool o) : Cell(u, c, o) {}

TreasureCell::TreasureCell(const TreasureCell& rhs) : Cell(rhs) {}

bool TreasureCell::uncover(int* h) {
    uncovered = true;
    if(hasOpponent) {
        *h -= 30;
    }
    std::cout << "You have found a treasure!" << std::endl;
    return true;
}