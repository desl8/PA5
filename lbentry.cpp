#include "lbentry.h"
using namespace std;

LBEntry::LBEntry() {
    playerName = "";
    playerScore = 0;
    next = nullptr;
}
LBEntry::LBEntry(int score, string name, LBEntry* nextEntry) {
    playerName = name;
    playerScore = score;
    next = nextEntry;
}
LBEntry::LBEntry(const LBEntry& rhs) {
    playerName = rhs.playerName;
    playerScore = rhs.playerScore;
    next = rhs.next;
}
void LBEntry::setPlayerScore(int score) {
    playerScore = score;
}
void LBEntry::setPlayerName(string name) {
    playerName = name;
}
void LBEntry::setNext(LBEntry* nextEntry) {
    next = nextEntry;
}
int LBEntry::getPlayerScore() {
    return playerScore;
}
string LBEntry::getPlayerName() {
    return playerName;
}
LBEntry* LBEntry::getNext() {
    return next;
}