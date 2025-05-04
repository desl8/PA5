#include "leaderboardmanager.h"

LeaderboardManager::LeaderboardManager() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

LeaderboardManager::LeaderboardManager(LBEntry* h, LBEntry* t) {
    head = h;
    tail = t;
    LBEntry* current = head;
    length = 0;
    while (current != nullptr) {
        length++;
        current = current->getNext();
    }
}

LeaderboardManager::LeaderboardManager(const LeaderboardManager& rhs) {
    head = rhs.head;
    tail = rhs.tail;
    length = rhs.length;
}

void LeaderboardManager::addEntry(int score, string name) {
    LBEntry* newEntry = new LBEntry(score, name, nullptr);
    if (head == nullptr) {
        head = newEntry;
        tail = newEntry;
    } else {
        tail->setNext(newEntry);
        tail = newEntry;
    }
    length++;
}

void LeaderboardManager::addEntryAtIndex(int index, int score, string name) {
    LBEntry* newEntry = new LBEntry(score, name, nullptr);
    if (index == 0) {
        newEntry->setNext(head);
        head = newEntry;
        if (tail == nullptr) {
            tail = newEntry;
        }
    } else {
        LBEntry* current = head;
        for (int i = 0; i < index - 1 && current != nullptr; i++) {
            current = current->getNext();
        }
        if (current == nullptr) {
            std::cout << "Index out of bounds." << std::endl;
            delete newEntry;
            return;
        }
        newEntry->setNext(current->getNext());
        current->setNext(newEntry);
        if (newEntry->getNext() == nullptr) {
            tail = newEntry;
        }
    }
    length++;
}
LBEntry* LeaderboardManager::getElementAtIndex(int index) {
    LBEntry* current = head;
    for (int i = 0; i < index && current != nullptr; i++) {
        current = current->getNext();
    }
    return current;
}

void LeaderboardManager::load(string filename){
    int i = 0;
    ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file: " << filename << std::endl;
    }
    else{
        string name;
        int score;
        while (file >> name >> score && i <= 10) {
            addEntry(score, name);
            i++;
        }
        file.close();
    }
    addEntry(-1, ""); // Add an empty entry to avoid segmentation fault
    length = i + 1;
}

void LeaderboardManager::write(string filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file: " << filename << std::endl;
        return;
    }
    LBEntry* current = head;
    while (current != nullptr) {
        if(current->getPlayerName() == "" || current->getPlayerScore() < 0) { //Avoid writing empty or negative scores
            current = current->getNext();
            continue;
        }
        file << current->getPlayerName() << " " << current->getPlayerScore();
        current = current->getNext();
        if(current->getNext() != nullptr) {
            file << std::endl; // Add a newline if not the last entry
        }
    }
    file.close();
}

int LeaderboardManager::getLength() {
    return length;
}