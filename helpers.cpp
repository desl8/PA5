#include "helpers.h"

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

void writeToFile(string playerName, const int playerScore){
    std::ofstream file(playerName + ".txt");
    if (!file.is_open()) {
        std::cout << "Error opening file: " << playerName + ".txt" << std::endl;
        return;
    }
    file << playerScore;
    file.close();
}

bool readFromFile(string playerName, int& playerScore){
    DIR *directoryPtr = opendir(".");
    ifstream file;
    struct dirent *directoryEntry;
    if (directoryPtr) {
        while ((directoryEntry = readdir(directoryPtr)) != NULL) {
            string filename = directoryEntry->d_name;
            string empty = "";
            if(filename == playerName + ".txt"){
                ifstream file(filename);
                if (!file.is_open()) {
                    std::cout << "Error opening file: " << playerName + ".txt" << std::endl;
                    return false;
                }
                file >> playerScore;
                file.close();
                return true;
            }
        }   
        closedir(directoryPtr); //close all directory
    }
    return false; // Return false if file not found
}

void writeLeaderboard(LeaderboardManager& leaderboard, string playerName, int winStreak){
    if(winStreak > leaderboard.getElementAtIndex(leaderboard.getLength() - 1)->getPlayerScore()){ // If eligible for leaderboard
        int placement;
        bool added = false;
        for(int i = 0; i < leaderboard.getLength(); i++){
            if (leaderboard.getElementAtIndex(i)->getPlayerName() == playerName) {
                leaderboard.deleteEntryAtIndex(i); // Remove the old entry
            }
            if(winStreak > leaderboard.getElementAtIndex(i)->getPlayerScore() && !added){
                added = true;
                leaderboard.addEntryAtIndex(i, winStreak, playerName);
                placement = i+1;
            }
        }
        if(placement < 11){
            std::cout << "Congratulations, " << playerName << "! You made it to the top 10!" << std::endl;
            std::cout << "You are in spot #" << placement << " with a streak of " << winStreak  << "!" << std::endl;
        }
    std::cout << "Thanks for playing!" << std::endl;
    std::cout << "Leaderboard:" << endl << leaderboard;
    leaderboard.write("leaderboard.txt");
    }
}