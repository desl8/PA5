#include <iostream>
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
    DynamicArray<DynamicArray<Cell>> cellMap;

    void generate(int, int, int, int);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();


    public:
        Board();
        Board(int, int, int, int, DynamicArray<DynamicArray<Cell>>);
        Board(const Board&);
        void setPlayerHealth(int);
        void setTreasureCollected(int);
        int getPlayerHealth();
        int getTreasureCollected();
        bool playGame();
        friend std::ostream& operator<<(std::ostream&, const Board&);
};