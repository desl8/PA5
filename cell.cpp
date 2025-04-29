#include "cell.h"

Cell::Cell(){
    uncovered = false;
    symbol = '?';
    hasOpponent = false;
}

Cell::Cell(bool u, char c, bool o){
    uncovered = u;
    symbol = c;
    hasOpponent = o;
}

Cell::Cell(const Cell& rhs){
    uncovered = rhs.uncovered;
    symbol = rhs.symbol;
    hasOpponent = rhs.hasOpponent;
}

void Cell::setSymbol(const char c){
    symbol = c;
}

void Cell::setOpponentState(const bool o){
    hasOpponent = o;
}

bool Cell::getUncovered() const{
    return uncovered;
}

char Cell::getSymbol() const{
    return symbol;
}

bool Cell::getOpponentState() const{
    return hasOpponent;
}

void Cell::display(){
    if(uncovered){
        std::cout << symbol;
    }
    else{
        std::cout << '.';
    }
}
