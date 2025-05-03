#include "emptycell.h"

EmptyCell::EmptyCell() : Cell() {
    symbol = '.';
}

EmptyCell::EmptyCell(bool u, char c, bool o) : Cell(u, c, o) {}

EmptyCell::EmptyCell(const EmptyCell& rhs) : Cell(rhs) {}

void EmptyCell::display(){
    if(hasOpponent){
        std::cout << 'O';
    }
    else{
        std::cout << "amogus";
    }
}

bool EmptyCell::uncover(int* h) {
    uncovered = true;
    if(hasOpponent) {
        *h -= 30;
    }
    return false;
}