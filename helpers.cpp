#include <iostream>
#include "cell.h"

std::ostream& operator<<(std::ostream& out, const Cell& c){
    out << "[ ";
    if(c.getUncovered()){
        out << c.symbol;
    }
    else{
        out << '.';
    }
    out << " ]";
    return out;
}