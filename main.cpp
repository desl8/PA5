#include <iostream>
#include <fstream>
#include <string>
#include "board.h"
#include "leaderboardmanager.h"


int main(){
    std::cout << "Welcome to the treasure hunt game!" << std::endl;
    string playerName;
    std::cout << "Please enter your name: ";
    std::cin >> playerName;
    LeaderboardManager leaderboard;
    leaderboard.load("leaderboard.txt");
    int winStreak = 0;
    std::cout << leaderboard.getLength() << std::endl;
    while(true){  
        Board board;
        if(board.playGame()){
            winStreak++;
            std::cout << "Congratulations! You won " << winStreak << " games in a row!" << std::endl;
        }
        else{
            std::cout << "Your win streak was: " << winStreak << std::endl;
            winStreak = 0;
        }
        char playAgain;
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
        while(playAgain != 'y' && playAgain != 'n'){
            std::cout << "Invalid input. Please enter 'y' or 'n': ";
            std::cin >> playAgain;
        }
        if(playAgain == 'n'){
            int lastindex;
            if(leaderboard.getLength() < 10){ // If leaderboard is empty
                lastindex = leaderboard.getLength();
            }
            else{
                lastindex = 9;
            }
            cout << lastindex << endl;
            if(winStreak > leaderboard.getElementAtIndex(lastindex)->getPlayerScore()){ // If eligible for leaderboard
                int placement;
                std::cout << "Congratulations! You made it to the leaderboard!" << std::endl;
                for(int i = 0; i < lastindex; i++){
                    if(winStreak > leaderboard.getElementAtIndex(i)->getPlayerScore()){
                        leaderboard.addEntryAtIndex(i, winStreak, playerName);
                        placement = i+1;
                        break;
                    }
                }
                if(lastindex < 9){ // If leaderboard is full
                    leaderboard.addEntry(winStreak, playerName);
                    placement = lastindex + 2;
                }
                std::cout << "You are in placement #" << placement << " with a score of " << winStreak << std::endl;
                leaderboard.addEntry(winStreak, playerName);
            std::cout << "Thanks for playing!" << std::endl;
            leaderboard.write("leaderboard.txt");
            return 0;
            }
        }
    }
    return 0; // So intellisense doesn't complain
}
