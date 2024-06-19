//
// Created by Marina Mata on 5/22/22.
//

#include "CheatingAI.h"
//
// Created by Marina Mata on 5/20/22.
//

#include "CheatingAI.h"
#include "CheatingAI.h"
#include "Board.h"
#include <vector>
using namespace BattleShip;
using namespace std;
CheatingAI::CheatingAI(int rows, int cols){
    row = rows;
    col = cols;
    //nextIndex[0] = 0;
    //nextIndex[1] = 0;
}/*
int* CheatingAI::getNextIndex(int nextIndex[2]){
    nextIndex[0]++;
    if(nextIndex[0] >= row){
        nextIndex[0] = 0;
    }
    nextIndex[1]++;
    if(nextIndex[1] >= col){
        nextIndex[1] = 0;
    }
    this->nextIndex[0] = nextIndex[0];
    this->nextIndex[1] = nextIndex[1];
    return nextIndex;
}*/
vector<int> CheatingAI::getCoords(Board a){
    vector<int> coordinates;
    char** board = a.getBoard();
    for(int i = 0;i<row;i++){
        for(int j=0;j<col;j++){
            if(isalpha(board[i][j]) && board[i][j] != 'X'&& board[i][j] != 'O'){
                coordinates.push_back(i);
                coordinates.push_back(j);
            }
        }
    }
    return coordinates;

}
