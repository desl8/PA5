#include <iostream>

class Cell{
    protected:
        bool uncovered;
        char symbol;
        bool hasOpponent;
    public:
        Cell();
        Cell(bool, char, bool);
        Cell(const Cell&);
        void setSymbol(const char);
        void setOpponentState(const bool);
        bool getUncovered() const;
        char getSymbol() const;
        bool getOpponentState() const;
        void display();

        virtual bool uncover();

        friend std::ostream& operator<<(std::ostream&, const Cell&);
};