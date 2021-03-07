#include "logic.hpp"
#include <QDebug>



Logic::Logic()
{
    // init gameboard

    for(int i = 0; i< ROWS; i++) {
        std::vector<std::string> column;
        board_.push_back(column);
        for(int j = 0; j<COLUMNS; j++) {
            board_.at(i).push_back(".");
        }
    }
    drawBoard();

}

bool Logic::addPiece(int column)
{
    if(column>= COLUMNS || column<0){
        return false;
    }

    for(int i = ROWS-1; i>=0; i--) {
        if(board_.at(i).at(column) == ".") {
            std::string mark;
            if(p1Turn_){
                mark = "X";
            } else{
                mark = "O";
            }
            board_.at(i).at(column)= mark;
            if(checkWin(i,column)){
                qDebug() << "GAME OVER";
                return true;
            }
            p1Turn_ = !p1Turn_;

            drawBoard();

            return true;
        }
    }
    return false;
}

void Logic::drawBoard()
{
    for(auto row: board_) {
        std::string line;
        for(std::string i: row) {
            line.append(i);
        }
        qDebug().noquote() <<QString::fromStdString(line);
    }
    if(p1Turn_) {
        qDebug() << "Player 1:\n";
    } else {
        qDebug() << "Player 2:\n";
    }
}

bool Logic::checkWin(int row, int column)
{
    std::string symbol = board_.at(row).at(column);
    int count = 0;
    for(int i = 0; i < ROWS; i++){
        if(board_.at(i).at(column)== symbol) {
            count++;
            if(count==WINAMOUNT){
                return true;
            }
        } else {
            count = 0;
        }
    }
    count = 0;
    for(int i = 0; i <COLUMNS; i++){
        if(board_.at(row).at(i)== symbol) {
            count++;
            if(count==WINAMOUNT){
                return true;
            }
        } else {
            count = 0;
        }
    }
    count = 0;

    // Set temp to diagonal bottom left
    int tempRow = row;
    int tempCol = column;
    while((tempRow < ROWS-1) && (tempCol > 0)) {
        tempRow++;
        tempCol--;
    }
    // Literate diagonal
    while((tempRow >= 0) && (tempCol < COLUMNS)){
        if(board_.at(tempRow).at(tempCol)== symbol) {
            count++;
            if(count==WINAMOUNT){
                return true;
            }
        } else {
            count = 0;
        }
        tempRow--;
        tempCol++;
    }

    // Set temp to diagonal top left
    tempRow = row;
    tempCol = column;
    while((tempRow > 0) && (tempCol > 0)) {
        tempRow--;
        tempCol--;
    }
    // Literate diagonal
    while((tempRow > ROWS) && (tempCol >= COLUMNS)){
        if(board_.at(tempRow).at(tempCol)== symbol) {
            count++;
            if(count==WINAMOUNT){
                return true;
            }
        } else {
            count = 0;
        }
        tempRow--;
        tempCol--;
    }


    return false;

}
