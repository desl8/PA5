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
    cellMap = new DynamicArray<DynamicArray<Cell*>>;
    opponentX = 0;
    opponentY = 0;
}

Board::Board(int x, int y, int h, int t, DynamicArray<DynamicArray<Cell*>>* map, int ox, int oy) {
    playerX = x;
    playerY = y;
    playerHealth = h;
    treasureCollected = t;
    cellMap = map;
    opponentX = ox;
    opponentY = oy;
}

Board::Board(const Board& rhs) {
    playerX = rhs.playerX;
    playerY = rhs.playerY;
    playerHealth = rhs.playerHealth;
    treasureCollected = rhs.treasureCollected;
    cellMap = rhs.cellMap;
    opponentX = rhs.opponentX;
    opponentY = rhs.opponentY;
}

void Board::generate(int rows, int cols, int traps, int treasures) {
   cellMap->clearArray();
    for (int i = 0; i < rows; i++) {
        DynamicArray<Cell*>* row = new DynamicArray<Cell*>;
        for (int j = 0; j < cols; j++) {
            Cell* temp = new EmptyCell();
            row->addElementToEndOfArr(temp);
        }
       cellMap->addElementToEndOfArr(*row);
    }
    int i = 0; //number of traps placed
    while (i < traps) {
        int x = rand() % rows;
        int y = rand() % cols;
        if (cellMap->getElementAtIndex(x).getElementAtIndex(y)->getSymbol() == '.' && !(x == 0 && y == 0)) { // If the cell is empty and not the start
            delete cellMap->getElementAtIndex(x).getElementAtIndex(y); // Free the memory of the existing cell
            Cell* temp = new TrapCell;
            cellMap->getElementAtIndex(x).replaceElementAtIndex(y, temp);
            i++;
        }
    }
    int j = 0; //number of treasures placed
    while (j < treasures) {
        int x = rand() % rows;
        int y = rand() % cols;
        bool edgeopen = false; //Whether the cell is surrounded
        if (cellMap->getElementAtIndex(x).getElementAtIndex(y)->getSymbol() == '.' && !(x == 0 && y == 0)) { // If the cell is empty
            if (y > 0) { // If not on the top edge
                if (cellMap->getElementAtIndex(x).getElementAtIndex(y - 1)->getSymbol() != 'T') { // If the cell above is not a trap
                    edgeopen = true;
                }
            }
            if (x > 0) { // If not on the left edge
                if (cellMap->getElementAtIndex(x - 1).getElementAtIndex(y)->getSymbol() != 'T') { // If the cell to the left is not a trap
                    edgeopen = true;
                }
            }
            if (y < rows - 1) { // If not on the bottom edge
                if (cellMap->getElementAtIndex(x).getElementAtIndex(y + 1)->getSymbol() != 'T') { // If the cell below is not a trap
                    edgeopen = true;
                }
            }
            if (x < cols - 1) { // If not on the right edge
                if (cellMap->getElementAtIndex(x + 1).getElementAtIndex(y)->getSymbol() != 'T') { // If the cell to the right is not a trap
                    edgeopen = true;
                }
            }
            if (edgeopen && !(x == 0 && y == 0)) { // If the cell is not surrounded and not the starting cell
                delete cellMap->getElementAtIndex(x).getElementAtIndex(y); // Free the memory of the existing cell
                Cell* temp = new TreasureCell;
                cellMap->getElementAtIndex(x).replaceElementAtIndex(y, temp);
                j++;
            }
        }
    }
    while (opponentX == 0 && opponentY == 0) { // Make sure the opponent is not on the same cell as the player
        opponentX = rand() % rows;
        opponentY = rand() % cols;
    }
    cellMap->getElementAtIndex(opponentY).getElementAtIndex(opponentX)->setOpponentState(true);
}

void Board::moveUp() {
    if (playerY > 0) {
        playerY--;
        if(cellMap->getElementAtIndex(playerY).getElementAtIndex(playerX)->uncover(&playerHealth)){
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
        if(cellMap->getElementAtIndex(playerY).getElementAtIndex(playerX)->uncover(&playerHealth)){
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
        if(cellMap->getElementAtIndex(playerY).getElementAtIndex(playerX)->uncover(&playerHealth)){
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
        if(cellMap->getElementAtIndex(playerY).getElementAtIndex(playerX)->uncover(&playerHealth)){
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
    generate(ROWS, COLS, TRAPS, TREASURES);
    while (playerHealth > 0) {
        std::cout << "Player Health: " << playerHealth << std::endl;
        std::cout << "Treasures Collected: " << treasureCollected << "/" << TREASURES << std::endl;
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
        cellMap->getElementAtIndex(opponentY).getElementAtIndex(opponentX)->setOpponentState(false);
        opponentX = rand() % cellMap->getCurrentNumElementsStored();
        opponentY = rand() % cellMap->getElementAtIndex(0).getCurrentNumElementsStored();
        cellMap->getElementAtIndex(opponentY).getElementAtIndex(opponentX)->setOpponentState(true);
        if(treasureCollected == TREASURES){
            std::cout << "Congratulations! You collected all treasures!" << std::endl;
            return true; // Game won
        }
    }
    std::cout << "Game Over! Your health has dropped to 0." << std::endl;
    std::cout << "You collected " << treasureCollected << " treasures." << std::endl;
    return false; // Game over
}

Board& Board::operator=(const Board& rhs) {
    playerX = rhs.playerX;
    playerY = rhs.playerY;
    playerHealth = rhs.playerHealth;
    treasureCollected = rhs.treasureCollected;
    cellMap = rhs.cellMap; //Using overloaded assignment operator
    opponentX = rhs.opponentX;
    opponentY = rhs.opponentY;
    return *this;
}

Board::~Board() {
    for (int i = 0; i < cellMap->getCurrentNumElementsStored(); i++) {
        for (int j = 0; j < cellMap->getElementAtIndex(i).getCurrentNumElementsStored(); j++) {
            delete cellMap->getElementAtIndex(i).getElementAtIndex(j);
        }
    }
    delete cellMap;
}