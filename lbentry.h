#ifndef LBENTRY_H
#define LBENTRY_H
#include <iostream>
using namespace std;
class LBEntry {
    private:
        string playerName;
        int playerScore;
        LBEntry* next;

    public:
        LBEntry();
        LBEntry(int, string, LBEntry*);
        LBEntry(const LBEntry&);
        void setPlayerScore(int);
        void setPlayerName(string);
        void setNext(LBEntry*);
        int getPlayerScore();
        string getPlayerName();
        LBEntry* getNext();
};
#endif