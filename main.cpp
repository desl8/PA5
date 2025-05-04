#include <iostream>
#include <fstream>
#include <string>
#include "board.h"
#include "leaderboardmanager.h"


int main(){
    std::cout << "Welcome to the treasure hunt game!" << std::endl;
    string playerName;
    bool validName = false;
    while(!validName){
        std::cout << "Please enter your name: ";
        getline(cin, playerName);
        validName = true; // Assume name is valid
        for(int i = 0; i < playerName.length(); i++){
            if(playerName[i] == ' '){
                std::cout << "Invalid name. Spaces are not allowed" << std::endl;
                validName = false; // Set to false if space is found
                break; // Exit the loop
            }
        }
        if(playerName == ""){
            std::cout << "Invalid name. Name cannot be empty." << std::endl;
            validName = false; // Set to false if name is empty
        }
    }
    LeaderboardManager leaderboard;
    leaderboard.load("leaderboard.txt");
    int winStreak = 0;
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
            if(winStreak > leaderboard.getElementAtIndex(leaderboard.getLength() - 1)->getPlayerScore()){ // If eligible for leaderboard
                int placement;
                bool added = false;
                for(int i = 0; i < leaderboard.getLength(); i++){
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
            return 0;
            }
        }
    }
    return 0; // So intellisense doesn't complain
}
