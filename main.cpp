#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "board.h"
#include "helpers.h"


int main(){
    std::cout << "Welcome to the treasure hunt game!" << std::endl;
    srand(time(0)); //Only need to seed once
    int winStreak = 0;
    while(true){  
        Board* board = new Board;
        if(board->playGame()){
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
            std::cout << "Thanks for playing!" << std::endl;
            delete board;
            return 0;
        }
    }
    return 0; // So intellisense doesn't complain
}
