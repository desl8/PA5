#include "trapcell.h"

TrapCell::TrapCell() : Cell() {
    symbol = 'X';
}

TrapCell::TrapCell(bool u, char c, bool o) : Cell(u, c, o) {}

TrapCell::TrapCell(const TrapCell& rhs) : Cell(rhs) {}

std::ostream& TrapCell::display(std::ostream& out){
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

bool TrapCell::uncover(int* h) {
    uncovered = true;
    *h -= 20;
    if(hasOpponent) {
        *h -= 30;
    }
    std::cout << "You have fallen into a trap! You lose 20 health!" << std::endl;
    return false;
}