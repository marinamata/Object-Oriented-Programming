//
// Created by Marina Mata on 5/22/22.
//

#include "HumanPlayer.h"
#include "HumanPlayer.h"
#include<iostream>
#include "HumanPlayer.h"
using namespace BattleShip;
using namespace std;

void HumanPlayer::setBoard(int row, int column){
    board.setDimensions(row, column);
    board.showBord();
}
Board HumanPlayer::getBoard(){
    return board;
}
void HumanPlayer::inputFireIndex(){

}
