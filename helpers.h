#ifndef HELPERS_H
#define HELPERS_H
#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>
#include "cell.h"
#include "board.h"
#include "leaderboardmanager.h"
std::ostream& operator<<(std::ostream& out, Cell& c);
std::ostream& operator<<(std::ostream& out, const Board& board);
std::ostream& operator<<(std::ostream& out, const LeaderboardManager& lbm);
void writeToFile(string playerName, const int playerScore);
bool readFromFile(string playerName, int& playerScore);
void writeLeaderboard(LeaderboardManager& lbm, string playerName, int playerScore);
#endif