#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "board.h"
#include "leaderboardmanager.h"
#include "helpers.h"


int main(){
    std::cout << "Welcome to the treasure hunt game!" << std::endl;
    srand(time(0)); // Only need to seed once
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
        else if(playerName == "leaderboard"){
            std::cout << "Bruh..." << std::endl;
            validName = false; // This idiot just tried to set their name to "leaderboard"
            //Why?
            //To nullify my hard work by writing their pitiful win streak over my leaderboard?
        }
    }
    LeaderboardManager* leaderboard = new LeaderboardManager;
    leaderboard->load("leaderboard.txt");
    int winStreak = 0;
    if(readFromFile(playerName, winStreak)){
        std::cout << "Welcome back, " << playerName << "! Your current win streak is: " << winStreak << std::endl;
    }
    else{
        std::cout << "Welcome, " << playerName << "! This is your first time playing!" << std::endl;
    }
    while(true){  
        Board* board = new Board;
        if(board->playGame()){
            winStreak++;
            std::cout << "Congratulations! You won " << winStreak << " games in a row!" << std::endl;
        }
        else{
            std::cout << "Your win streak was: " << winStreak << std::endl;
            writeLeaderboard(*leaderboard, playerName, winStreak);
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
            writeLeaderboard(*leaderboard, playerName, winStreak);
            writeToFile(playerName, winStreak);
            delete leaderboard
            delete board;
            return 0;
        }
    }
    return 0; // So intellisense doesn't complain
}
