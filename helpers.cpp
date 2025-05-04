#include <iostream>
#include "cell.h"
#include "board.h"
#include "leaderboardmanager.h"

std::ostream& operator<<(std::ostream& out, Cell& c){
    out << "[ ";
    c.display(out);
    out << " ]";
    return out;
}

std::ostream& operator<<(std::ostream& out, const Board& board){
    for(int i = 0; i < board.cellMap->getCurrentNumElementsStored(); i++){
        for(int j = 0; j < board.cellMap->getElementAtIndex(i).getCurrentNumElementsStored(); j++){
            if(i == board.playerY && j == board.playerX){
                out << "[ P ]"; // Player position
            }
            else{
                out << *board.cellMap->getElementAtIndex(i).getElementAtIndex(j);
            }
        }
        out << std::endl;
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, const LeaderboardManager& lbm){
    int i = 0;
    LBEntry* current = lbm.head;
    while(current != nullptr && i < 10 && current->getPlayerScore() >= 0){
        out <<"#" << i+1;
        if(i < 9){
            out << " ";
        }
        out << " | " << current->getPlayerName() << ": " << current->getPlayerScore() << std::endl;
        current = current->getNext();
        i++;
    }
    return out;
}