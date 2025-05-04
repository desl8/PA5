#include "treasurecell.h"

TreasureCell::TreasureCell() : Cell() {
    symbol = 'T';
}

TreasureCell::TreasureCell(bool u, char c, bool o) : Cell(u, c, o) {}

TreasureCell::TreasureCell(const TreasureCell& rhs) : Cell(rhs) {}

std::ostream& TreasureCell::display(std::ostream& out){
    if(hasOpponent){
        out << 'O';
    }
    else if(uncovered){
        out << symbol;
    }
    else{
        out << '?';
    }
    return out;
}

bool TreasureCell::uncover(int* h){
    if(hasOpponent) {
        *h -= 30;
    }
    if(!uncovered){
        uncovered = true;
        std::cout << "You have found a treasure!" << std::endl;
        return true;
    }
    else{
        std::cout << "You have already uncovered this treasure!" << std::endl;
        return false;
    }
}