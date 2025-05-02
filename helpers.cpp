#include <iostream>
#include "cell.h"
#include "board.h"

std::ostream& operator<<(std::ostream& out, const Cell& c){
    out << "[ ";
    //if(c.getUncovered()){
        out << c.symbol;
    //}
    //else{
    //    out << '.';
    //}
    out << " ]";
    return out;
}

std::ostream& operator<<(std::ostream& out, const Board& board){
    for(int i = 0; i < board.cellMap.getCurrentNumElementsStored(); i++){
        for(int j = 0; j < board.cellMap.getElementAtIndex(i).getCurrentNumElementsStored(); j++){
            if(i == board.playerY && j == board.playerX){
                out << "[ P ]"; // Player position
            }
            else{
                out << *board.cellMap.getElementAtIndex(i).getElementAtIndex(j);
            }
        }
        out << std::endl;
    }
    return out;
}