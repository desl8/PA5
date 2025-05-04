#include "emptycell.h"

EmptyCell::EmptyCell() : Cell() {
    symbol = '.';
}

EmptyCell::EmptyCell(bool u, char c, bool o) : Cell(u, c, o) {}

EmptyCell::EmptyCell(const EmptyCell& rhs) : Cell(rhs) {}

std::ostream& EmptyCell::display(std::ostream& out){
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

bool EmptyCell::uncover(int* h) {
    uncovered = true;
    if(hasOpponent) {
        *h -= 30;
    }
    return false;
}