#include "dynamicArray.h"
#include "cell.h"

class Board{
    int playerX;
    int playerY;
    int playerHealth;
    int treasureCollected;
    DynamicArray<DynamicArray<Cell>> cellMap;

    void generate(int, int);

    public:
        Board();
        Board(int, int, int, int, DynamicArray<DynamicArray<Cell>>);
        void setPlayerX(int);
        void setPlayerY(int);
        void setPlayerHealth(int);
        void setTreasureCollected(int);
        int getPlayerX();
        int getPlayerY();
        int getPlayerHealth();
        int getTreasureCollected();
};