#include "dynamicArray.h"
#include "cell.h"

class Board{
    int playerX;
    int playerY;
    int playerHealth;
    int treasureCollected;
    DynamicArray<DynamicArray<Cell>> cellMap;

    void generate(int, int);
    bool moveUp();
    bool moveDown();
    bool moveLeft();
    bool moveRight();


    public:
        Board();
        Board(int, int, int, int, DynamicArray<DynamicArray<Cell>>);
        void setPlayerHealth(int);
        void setTreasureCollected(int);
        int getPlayerHealth();
        int getTreasureCollected();
        bool playGame();
};