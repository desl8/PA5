#ifndef HELPERS_H
#define HELPERS_H
#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>
#include "cell.h"
#include "board.h"
std::ostream& operator<<(std::ostream& out, Cell& c);
std::ostream& operator<<(std::ostream& out, const Board& board);
#endif