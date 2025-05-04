#ifndef LEADERBOARDMANAGER_H
#define LEADERBOARDMANAGER_H
#include <iostream>
#include "lbEntry.h"
using namespace std;
class LeaderboardManager{
    private:
        LBEntry* head;
        LBEntry* tail;

    public:
        LeaderboardManager();
        LeaderboardManager(LBEntry*, LBEntry*);
        LeaderboardManager(const LeaderboardManager&);
        void addEntry(int, std::string, LBEntry*);
        LBEntry* getElementAtIndex(int);
};
#endif