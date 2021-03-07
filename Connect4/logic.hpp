#ifndef LOGIC_HPP
#define LOGIC_HPP
#include <vector>
#include <string>

using GameBoard = std::vector<std::vector<std::string>>;

class Logic
{
public:
    Logic();

    bool addPiece(int column);

private:

    void drawBoard();

    bool checkWin(int row, int column);

    const int ROWS = 6;
    const int COLUMNS = 7;
    const int WINAMOUNT = 4;

    GameBoard board_;
    bool p1Turn_ = true;
};

#endif // LOGIC_HPP
