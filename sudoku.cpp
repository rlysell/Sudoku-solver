#include<vector>
#include<iostream>
#include"sudoku.h"


Solver::Solver(std::vector<std::vector<int>> &board_) : board(board_){
    rows = board_.size();
    cols = board_[0].size();
}

void Solver::solve ( ){
    if(canfill()){
        std::cout << "Solved\n";
    }
    else{
        std::cout << "Failed\n";
    }
}

Position Solver::findEmpty ( )
{
    for (int row = 0; row < rows; row++ ){
        for (int col = 0; col < cols; col++ ){
            if (board[row][col] == 0){
                return Position(row, col);
            }
        }
    }
    return Position(-1, -1);
}

const bool Solver::isEmpty (const int i, const int j)
{
    if (board[i][j] == 0){
        return true;
    }
    return false;
}

const bool Solver::isInRow (const int row, const int value)
{
    for (int col = 0; col < cols; col++){
        if (board[row][col] == value){
            return true;
        }
    }
    return false;
}

const bool Solver::isInCol (const int col, const int value)
{
    for ( int row = 0; row < rows; row++ ){
        if ( board [row][col] == value ){
            return true;
        }
    }
    return false;
}

const bool Solver::isInBox (const int row, const int col, const int value)
{
    int xbox = row / 3;
    int ybox = col / 3;
    for (int i = xbox * 3; i < xbox * 3 + 3; i++){
        for(int j = ybox * 3; j < ybox * 3 + 3; j++){
            if (board[i][j] == value){
                return true;
            }
        }
    }
    return false;
}

const bool Solver::isValid (const int row, const int col, const int value)
{
    if (isInRow(row, value) || isInCol(col, value) || isInBox(row, col, value)){
        return false;
    }
    return true;
}

bool Solver::canfill ( )
{
    Position pos = findEmpty();
    if (pos.x == -1 || pos.y == -1){
        return true;
    }
    int row = pos.x; int col = pos.y;
    for ( int value = 1; value < 10; value++ ){
        if ( isValid (row, col, value) ){
            board [row][col] = value;
            if (canfill ()){
                return true;
            }
            board [row][col] = 0;
        }
    }
    return false;
}

const void Solver::printBoard ( )
{
    std::cout << "--------------------------------------------------------------------\n";
    for ( int i = 0; i < 9; i++ ){
        for ( int j = 0; j < 9; j++ ){
            std::cout << board [i][j] << "\t";
            if (j > 0 && j < 8 && (j + 1) % 3 == 0){
                std::cout << "|"; 
            }
        }
        std::cout << "\n";
        if (i > 0 && (i + 1) % 3 == 0){
            std::cout << "--------------------------------------------------------------------\n";
        }
    }
}