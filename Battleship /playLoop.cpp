//
// Created by Marina Mata on 5/9/22.
//
#include "Board.h"
#include "Player.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include<algorithm>
#include "playLoop.h"

using namespace std;
using namespace BattleShip;
bool  playLoop:: isValid(string str){
    str.erase(remove(str.begin(), str.end(), ' '), str.end());//this checks h and v
    if(str.length()==1){
        while(str=="H"||str=="V"||str=="h"||str=="v"){
            return true;
        }
    }
    return false;
}

bool playLoop:: isNumber(const string &str, int limit) { //checking integers
    if(stoi(str) < 0 || stoi(str) >= limit){
        return false;
    }
    for (char const &c : str) {
        if (std::isdigit(c) == 0 )
            return false;
    }
    return true;
}

void playLoop:: runLoop(Player player1, int rows, int column, Board b1,Player player2, Board b2 ) {
    this->row = rows;
    this->col = column;
    bool win = false;//set the game to false cuz otherwise game over
    Player curPlayer = player1;
    Player prevPlayer = curPlayer;
    Board b11; // Firing board of player 1
    b11.setDimensions(row, column);
    Board b22; // Firing board of player 2
    b22.setDimensions(row, column);
    Board curBoard = b1;
    Board prevBoard = curBoard;
    Board curFiringBoard = b11;
    Board previousFiring = curFiringBoard;
    string attackRow, attackCol;

    do {
        while (true) {
            cout << curPlayer.getName() << "\'s Firing Board" << endl;
            curFiringBoard.showBord();
            cout<<endl<<endl;
            cout << curPlayer.getName() << "\'s Placement Board" << endl;
            curBoard.showBord();
            cout << curPlayer.getName()
                 << ", where would you like to fire?\nEnter your attack coordinate in "
                    "the form row col: ";
            cin >> attackRow;
            cin >> attackCol;
            if (!isNumber(attackRow,row) || !isNumber(attackCol,col)) {
                continue;
            }
            else{
                break;
            }
        }
        previousFiring = curFiringBoard;
        prevPlayer = curPlayer;
        prevBoard = curBoard;
        if (curPlayer.getNumber() == 1) {
            curPlayer = player2;
            curBoard = b2;
            curFiringBoard = b22;
        } else {
            curPlayer = player1;
            curBoard = b1;
            curFiringBoard = b11;
        }

        previousFiring.updateBoard(curBoard, stoi(attackRow), stoi(attackCol));
        cout << prevPlayer.getName() << "\'s Firing Board" << endl;
        previousFiring.showBord();
        cout<<endl<<endl;
        cout << prevPlayer.getName() << "\'s Placement Board" << endl;
        prevBoard.showBord();
        char currentShip = curBoard.getValue(stoi(attackRow), stoi(attackCol));
        if (currentShip != '*') {
            cout << prevPlayer.getName() << " hit " << curPlayer.getName() << "'s " << currentShip << "!" << endl;

        } else {
            cout << "Missed!"<<endl;
        }

        curBoard.updateBoard(curBoard, stoi(attackRow), stoi(attackCol));
        if(curBoard.isShipDestroyed(currentShip)){
            cout << prevPlayer.getName() << " destroyed " << curPlayer.getName() << "'s " << currentShip <<"!"<< endl<<endl;
        }
        if(curBoard.destroy()){
            cout << prevPlayer.getName() << " won the game!" << endl;
            win = true;
        }
    } while (!win);
}