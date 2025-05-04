#ifndef LEADERBOARDMANAGER_H
#define LEADERBOARDMANAGER_H
#include <iostream>
#include <fstream>
#include <string>
#include "lbentry.h"
using namespace std;
class LeaderboardManager{
    private:
        LBEntry* head;
        LBEntry* tail;
        int length;

    public:
        LeaderboardManager();
        LeaderboardManager(LBEntry*, LBEntry*);
        LeaderboardManager(const LeaderboardManager&);
        void addEntry(int, std::string);
        void addEntryAtIndex(int, int, string);
        LBEntry* getElementAtIndex(int);
        void load(string);
        void write(string);
        int getLength();
        void deleteEntryAtIndex(int index);

        friend std::ostream& operator<<(std::ostream&, const LeaderboardManager&);

        LeaderboardManager& operator=(const LeaderboardManager&);

        ~LeaderboardManager();
};
#endif