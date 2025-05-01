#include "board.h"
#define ROWS 5
#define COLS 5
#define TREASURES 5
#define TRAPS 5

Board::Board() {
    playerX = 0;
    playerY = 0;
    playerHealth = 100;
    treasureCollected = 0;
    cellMap = DynamicArray<DynamicArray<Cell>>();

    generate(ROWS, COLS, TRAPS, TREASURES);
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
        if (cellMap.getElementAtIndex(x).getElementAtIndex(y).getSymbol() == '.') { // If the cell is empty
            cellMap.getElementAtIndex(x).replaceElementAtIndex(y, TrapCell());
            i++;
        }
    }
    int j = 0; //number of traps placed
    while (j < treasures) {
        int x = rand() % rows;
        int y = rand() % cols;
        bool edgeopen = false; //Whether the cell is surrounded
        if (cellMap.getElementAtIndex(x).getElementAtIndex(y).getSymbol() == '.') { // If the cell is empty
            if (y>0){ // If not on the top edge
                if(cellMap.getElementAtIndex(x).getElementAtIndex(y-1).getSymbol() != 'T'){ // If the cell above is not a trap
                    edgeopen = true;
                }
            }
            if (x>0){ // If not on the left edge
                if(cellMap.getElementAtIndex(x-1).getElementAtIndex(y).getSymbol() != 'T'){ // If the cell to the left is not a trap
                    edgeopen = true;
                }
            }
            if (y<rows-1){ // If not on the bottom edge
                if(cellMap.getElementAtIndex(x).getElementAtIndex(y+1).getSymbol() != 'T'){ // If the cell below is not a trap
                    edgeopen = true;
                }
            }
            if (x<cols-1){ // If not on the right edge
                if(cellMap.getElementAtIndex(x+1).getElementAtIndex(y).getSymbol() != 'T'){ // If the cell to the right is not a trap
                    edgeopen = true;
                }
            }
            if (edgeopen){
                cellMap.getElementAtIndex(x).replaceElementAtIndex(y, TrapCell());
                j++;
            }
        }
    }
}

void Board::moveUp() {
    if (playerY > 0) {
        playerY--;
        if(cellMap.getElementAtIndex(playerX).getElementAtIndex(playerY).uncover(&playerHealth)){
            treasureCollected++;
        }
    }
    else{
        std::cout << "You cannot move up!" << std::endl;
    }
}

void Board::moveDown() {
    if (playerY < ROWS - 1) {
        playerY++;
        if(cellMap.getElementAtIndex(playerX).getElementAtIndex(playerY).uncover(&playerHealth)){
            treasureCollected++;
        }
    }
    else{
        std::cout << "You cannot move down!" << std::endl;
    }
}

void Board::moveLeft() {
    if (playerX > 0) {
        playerX--;
        if(cellMap.getElementAtIndex(playerX).getElementAtIndex(playerY).uncover(&playerHealth)){
            treasureCollected++;
        }
    }
    else{
        std::cout << "You cannot move left!" << std::endl;
    }
}

void Board::moveRight() {
    if (playerX < COLS - 1) {
        playerX++;
        if(cellMap.getElementAtIndex(playerX).getElementAtIndex(playerY).uncover(&playerHealth)){
            treasureCollected++;
        }
    }
    else{
        std::cout << "You cannot move right!" << std::endl;
    }
}

void Board::setPlayerHealth(int h) {
    playerHealth = h;
}
void Board::setTreasureCollected(int t) {
    treasureCollected = t;
}

int Board::getPlayerHealth() {
    return playerHealth;
}
int Board::getTreasureCollected() {
    return treasureCollected;
}

bool Board::playGame() {
    while (playerHealth > 0) {
        std::cout << "Player Health: " << playerHealth << std::endl;
        std::cout << "Treasures Collected: " << treasureCollected/TREASURES << std::endl;
        std::cout << *this << std::endl;

        char move;
        std::cout << "Enter your move (w/a/s/d): ";
        std::cin >> move;

        switch (move) {
            case 'w':
                moveUp();
                break;
            case 's':
                moveDown();
                break;
            case 'a':
                moveLeft();
                break;
            case 'd':
                moveRight();
                break;
            default:
                std::cout << "Invalid move!" << std::endl;
        }
        if(treasureCollected == TREASURES){
            std::cout << "Congratulations! You collected all treasures!" << std::endl;
            return true; // Game won
        }
    }
    std::cout << "Game Over! Your health has dropped to 0." << std::endl;
    std::cout << "You collected " << treasureCollected << " treasures." << std::endl;
    return false; // Game over
}