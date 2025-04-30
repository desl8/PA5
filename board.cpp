#include "board.h"

Board::Board() {
    playerX = 0;
    playerY = 0;
    playerHealth = 100;
    treasureCollected = 0;
    cellMap = DynamicArray<DynamicArray<Cell>>();

    generate(5, 5, 5, 5);
}

Board::Board(int x, int y, int h, int t, DynamicArray<DynamicArray<Cell>> map) {
    playerX = x;
    playerY = y;
    playerHealth = h;
    treasureCollected = t;
    cellMap = map;
}

Board::Board(const Board& rhs) {
    playerX = rhs.playerX;
    playerY = rhs.playerY;
    playerHealth = rhs.playerHealth;
    treasureCollected = rhs.treasureCollected;
    cellMap = rhs.cellMap;
}

void Board::generate(int rows, int cols, int traps, int treasures) {
    cellMap.clearArray();
    for (int i = 0; i < rows; i++) {
        DynamicArray<Cell> row = DynamicArray<Cell>();
        for (int j = 0; j < cols; j++) {
            row.addElementToEndOfArr(EmptyCell());
        }
        cellMap.addElementToEndOfArr(row);
    }
    int i = 0; //number of traps placed
    while (i < traps) {
        int x = rand() % rows;
        int y = rand() % cols;
        if (cellMap.getElementAtIndex(x).getElementAtIndex(y).getSymbol() == '.') {
            cellMap.getElementAtIndex(x).replaceElementAtIndex(y, TrapCell());
            i++;
        }
    }
}