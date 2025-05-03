#include "treasurecell.h"

TreasureCell::TreasureCell() : Cell() {
    symbol = 'T';
}

TreasureCell::TreasureCell(bool u, char c, bool o) : Cell(u, c, o) {}

TreasureCell::TreasureCell(const TreasureCell& rhs) : Cell(rhs) {}

void TreasureCell::display(){
    if(hasOpponent){
        std::cout << 'O';
    }
    else if(uncovered){
        std::cout << symbol;
    }
    else{
        std::cout << '.';
    }
}

bool TreasureCell::uncover(int* h) {
    uncovered = true;
    if(hasOpponent) {
        *h -= 30;
    }
    std::cout << "You have found a treasure!" << std::endl;
    return true;
}