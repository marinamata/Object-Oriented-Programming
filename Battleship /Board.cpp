//
// Created by Marina Mata on 5/9/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "Board.h"
#include <iostream>
using namespace BattleShip;
using namespace std;

void Board::setDimensions(int r, int c){ //setting the board, finding row and column
    rows = r;
    cols = c;
    board = new char*[rows];//*board = (char *)malloc(rows * sizeof(char *)); // Allocate row pointers
    for(int i = 0; i < rows; i++){
        board[i] = new char[cols];
        for(int j = 0; j< cols;j++){
            board[i][j] = '*';  // Allocate each row separately
        }
    }
}
bool Board::setBoard(int row1, int column1,char alignment, char name, int length ) {//update the placement board
    //check for out of bound and overflow
    int row2 = row1;
    int column2 = column1;
    int bounds = row2 + length-1;
    int bounds2 = column2+ length-1;
    if (alignment == 'h') {
        if(bounds2<cols){
            //board[row1][column1] //3 and 5

            for (int i = 0; i < length; i++) {
                if(isalpha(board[row2][column2+i])){
                    return false;
                }
                board[row2][column2+i] = name;

            }
        }else{
            return false;
        }

    } else {
        if(bounds<rows){
            for (int i = 0; i < length; i++) {
                if(isalpha(board[row2][column2+i])){
                    return false;
                }
                board[row2+i][column2] = name; // do the horizonatal one

            }
        }
        else{
            return false;
        }


    }
    showBord();
    return true;
}
void Board::showBord(){ //prints out the board
    cout << "  ";
    for (int i = 0; i < cols; i++) {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < rows; i++) {
        cout << i << " ";
        for (int s = 0; s < cols; s++) {
            cout << board[i][s] << " ";
        }
        cout << endl;
    }
    //cout << endl;
}
/*char[][] Board::getBoard(){
  return board;
}*/
bool Board::checkHit(int row, int col){ //checks if there is a hit or not

    if(board[row][col]=='*'){
        return false;
    }
    return true;
}
void Board::updateBoard(Board b,int r, int c){
    if(b.getValue(r,c) != '*'){
        board[r][c] = 'X';
    }
    else{
        board[r][c] = 'O';
    }
}
char Board::getValue(int r, int c){
    return board[r][c];
}
bool Board::destroy(){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(isalpha(board[i][j]) && board[i][j] != 'X' && board[i][j] != 'O'){
                return false;
            }
        }
    }
    return true;
}
bool Board::isShipDestroyed(char ship){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(board[i][j] == ship){
                return false;
            }
        }
    }
    return true;
}