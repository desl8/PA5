#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "dynamicArray.h"
#include "cell.h"
#include "emptycell.h"
#include "treasurecell.h"
#include "trapcell.h"

class Board{
    int playerX;
    int playerY;
    int playerHealth;
    int treasureCollected;
    int opponentX;
    int opponentY;
    DynamicArray<DynamicArray<Cell*>>* cellMap;

    void generate(int, int, int, int);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();


    public:
        Board();
        Board(int, int, int, int, DynamicArray<DynamicArray<Cell*>>*, int, int);
        Board(const Board&);
        void setPlayerHealth(int);
        void setTreasureCollected(int);
        int getPlayerHealth();
        int getTreasureCollected();
        bool playGame();
        friend std::ostream& operator<<(std::ostream&, const Board&);

        Board& operator=(const Board&);

        ~Board();
};
#endif