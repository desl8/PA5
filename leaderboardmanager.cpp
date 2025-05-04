#include <iostream>
#include "leaderboardmanager.h"

LeaderboardManager::LeaderboardManager() {
    head = nullptr;
    tail = nullptr;
}
LeaderboardManager::LeaderboardManager(LBEntry* h, LBEntry* t) {
    head = h;
    tail = t;
}
LeaderboardManager::LeaderboardManager(const LeaderboardManager& rhs) {
    head = rhs.head;
    tail = rhs.tail;
}
void LeaderboardManager::addEntry(int score, std::string name, LBEntry* nextEntry) {
    LBEntry* newEntry = new LBEntry(score, name, nextEntry);
    if (head == nullptr) {
        head = newEntry;
        tail = newEntry;
    } else {
        tail->setNext(newEntry);
        tail = newEntry;
    }
}
LBEntry* LeaderboardManager::getElementAtIndex(int index) {
    LBEntry* current = head;
    for (int i = 0; i < index && current != nullptr; i++) {
        current = current->getNext();
    }
    return current;
}