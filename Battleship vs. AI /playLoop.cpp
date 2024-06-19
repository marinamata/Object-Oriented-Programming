//
// Created by Marina Mata on 5/22/22.
//

#include "playLoop.h"
//
// Created by Marina Mata on 5/20/22.
//

#include "playLoop.h"
//
// Created by Marina Mata on 5/9/22.
//
#include "playLoop.h"
#include "Board.h"
#include "Player.h"
#include "CheatingAI.h"
#include "RandomAI.h"
//#include "AI.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
using namespace BattleShip;

bool playLoop::isValid(string str) {
    str.erase(remove(str.begin(), str.end(), ' '),
              str.end()); // this checks h and v
    if (str.length() == 1) {
        while (str == "H" || str == "V" || str == "h" || str == "v") {
            return true;
        }
    }
    return false;
}

bool playLoop::isNumber(const string &str, int limit) { // checking integers
    if (stoi(str) < 0 || stoi(str) >= limit) {
        return false;
    }
    for (char const &c : str) {
        if (std::isdigit(c) == 0)
            return false;
    }
    return true;
}


void playLoop::runLoop(RandomAI player1, CheatingAI player2, Board b1, Board b2, int row, int column, std::mt19937& generator) {
    string player1Firing = player1.getName()+"\'s Firing Board";
    string player2Firing = player2.getName()+"\'s Firing Board";
    string player1Placing = player1.getName()+"\'s Placement Board";
    string player2Placing = player2.getName()+"\'s Placement Board";
    string curPlayerName = player1.getName();
    string prevPlayerName = player2.getName();
    int curPlayer = 1;
    int prevPlayer = 2;

    this->row = row;
    this->col = column;
    bool win = false; // set the game to false cuz otherwise game over
    Board b11; // Firing board of player 1
    b11.setDimensions(row, column);
    Board b22; // Firing board of player 2
    b22.setDimensions(row, column);
    Board curBoard = b1;
    Board prevBoard = curBoard;
    Board curFiringBoard = b11;
    Board previousFiring = curFiringBoard;
    int attackRow;
    int attackCol;

    do {
        while (true) {

            if(curPlayer == 1){
                pair<int, int> attack = player1.getAttack(generator);
                attackRow = attack.first;
                attackCol = attack.second;
            }
            else{
                vector<int> attack = player2.getCoords(prevBoard);
                attackRow = attack[0];
                attackCol = attack[1];
            }

            break;
            /*
            if (!isNumber(attackRow, row) || !isNumber(attackCol, col)) {
                continue;
            } else {
                break;
            }*/
        }
        previousFiring = curFiringBoard;
        prevPlayer = curPlayer;
        prevBoard = curBoard;
        prevPlayerName = curPlayerName;
        if (curPlayer == 1) {
            curPlayer = 2;
            curBoard = b2;
            curFiringBoard = b22;
            curPlayerName = player2.getName();
        } else {
            curPlayer = 1;
            curBoard = b1;
            curFiringBoard = b11;
            curPlayerName = player1.getName();
        }

        previousFiring.updateBoard(curBoard, attackRow, attackCol);
        if(prevPlayer == 1)
            cout << player1Firing << endl;
        else
            cout << player2Firing << endl;
        previousFiring.showBord();
        cout << endl<<endl;
        if(prevPlayer == 1)
            cout << player1Placing << endl;
        else
            cout << player2Placing << endl;
        prevBoard.showBord();

        char currentShip = curBoard.getValue(attackRow, attackCol);
        if (currentShip != '*') {
            cout << prevPlayerName << " hit " << curPlayerName << "'s "
                 << currentShip << "!"<<endl;

        } else {
            cout << "Missed."<<endl;
            //cout<<endl;
        }
        curBoard.updateBoard(curBoard, attackRow, attackCol);
        if (curBoard.isShipDestroyed(currentShip)) {

            cout << prevPlayerName << " destroyed " << curPlayerName
                 << "'s " << currentShip << "!" << endl;
            cout << endl;
        }else{cout<<endl;}
        if (curBoard.destroy()) {
            //cout<<endl;
            cout << prevPlayerName << " won the game!" << endl;
            win = true;
        }
    } while (!win);
}


void playLoop::runLoop(CheatingAI player1, RandomAI player2, Board b1, Board b2, int row, int column, std::mt19937& generator) {
    string player1Firing = player1.getName()+"\'s Firing Board";
    string player2Firing = player2.getName()+"\'s Firing Board";
    string player1Placing = player1.getName()+"\'s Placement Board";
    string player2Placing = player2.getName()+"\'s Placement Board";
    string curPlayerName = player1.getName();
    string prevPlayerName = player2.getName();
    int curPlayer = 1;
    int prevPlayer = 2;

    this->row = row;
    this->col = column;
    bool win = false; // set the game to false cuz otherwise game over
    Board b11; // Firing board of player 1
    b11.setDimensions(row, column);
    Board b22; // Firing board of player 2
    b22.setDimensions(row, column);
    Board curBoard = b1;
    Board prevBoard = b2;
    Board curFiringBoard = b11;
    Board previousFiring = curFiringBoard;
    int attackRow;
    int attackCol;

    do {
        while (true) {

            if(curPlayer == 1){
                vector<int> attack = player1.getCoords(prevBoard);
                attackRow = attack[0];
                attackCol = attack[1];

            }
            else{
                pair<int, int> attack = player2.getAttack(generator);
                attackRow = attack.first;
                attackCol = attack.second;
            }

            break;
            /*
            if (!isNumber(attackRow, row) || !isNumber(attackCol, col)) {
                continue;
            } else {
                break;
            }*/
        }
        previousFiring = curFiringBoard;
        prevPlayer = curPlayer;
        prevBoard = curBoard;
        prevPlayerName = curPlayerName;
        if (curPlayer == 1) {
            curPlayer = 2;
            curBoard = b2;
            curFiringBoard = b22;
            curPlayerName = player2.getName();
        } else {
            curPlayer = 1;
            curBoard = b1;
            curFiringBoard = b11;
            curPlayerName = player1.getName();
        }

        previousFiring.updateBoard(curBoard, attackRow, attackCol);
        if(prevPlayer == 1)
            cout << player1Firing << endl;
        else
            cout << player2Firing << endl;
        previousFiring.showBord();
        cout << endl<<endl;
        if(prevPlayer == 1)
            cout << player1Placing << endl;
        else
            cout << player2Placing << endl;
        prevBoard.showBord();

        char currentShip = curBoard.getValue(attackRow, attackCol);
        if (currentShip != '*') {
            cout << prevPlayerName << " hit " << curPlayerName << "'s "
                 << currentShip << "!"<<endl;

        } else {
            cout << "Missed."<<endl;
            //cout<<endl;
        }
        curBoard.updateBoard(curBoard, attackRow, attackCol);
        if (curBoard.isShipDestroyed(currentShip)) {

            cout << prevPlayerName << " destroyed " << curPlayerName
                 << "'s " << currentShip << "!" << endl;
            cout << endl;
        }else{cout<<endl;}
        if (curBoard.destroy()) {
            //cout<<endl;
            cout << prevPlayerName << " won the game!" << endl;
            win = true;
        }
    } while (!win);
}

void playLoop::runLoop(CheatingAI player1, CheatingAI player2, Board b1, Board b2, int row, int column, std::mt19937& generator) {
    this->row = row;
    this->col = column;
    bool win = false; // set the game to false cuz otherwise game over

    CheatingAI curPlayer = player1;
    CheatingAI prevPlayer = curPlayer;
    Board b11; // Firing board of player 1
    b11.setDimensions(row, column);
    Board b22; // Firing board of player 2
    b22.setDimensions(row, column);
    Board curBoard = b1;
    Board prevBoard = b2;
    Board curFiringBoard = b11;
    Board previousFiring = b22;
    int attackRow;
    int attackCol;

    do {
        while (true) {
            // cout << curPlayer.getName() << "\'s Firing Board" << endl;
            //curFiringBoard.showBord();
            //cout << endl << endl;
            //cout << curPlayer.getName() << "\'s Placement Board" << endl;
            //curBoard.showBord();
            /*cout << curPlayer.getName()
                 << ", where would you like to fire?\nEnter your attack coordinate
            in " "the form row col: "; cin >> attackRow; cin >> attackCol;*/
            // cout<<typeid(curPlayer).name();

            //-->Fix the function overriding.
            //index = curPlayer.getNextIndex(index);
            vector<int> attack = curPlayer.getCoords(prevBoard);
            attackRow = attack[0];
            attackCol = attack[1];
            break;
            /*
            if (!isNumber(attackRow, row) || !isNumber(attackCol, col)) {
                continue;
            } else {
                break;
            }*/
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

        previousFiring.updateBoard(curBoard, attackRow, attackCol);
        cout<<prevPlayer.getName() << "\'s Firing Board" << endl;
        previousFiring.showBord();
        //cout << endl;
        cout << endl<<endl<<prevPlayer.getName() << "\'s Placement Board" << endl;
        prevBoard.showBord();
        char currentShip = curBoard.getValue(attackRow, attackCol);
        if (currentShip != '*') {
            //cout<<endl;
            cout << prevPlayer.getName() << " hit " << curPlayer.getName() << "'s "
                 << currentShip << "!" << endl;
            //cout<<endl;


        } else {
            cout << "Missed!" << endl;
        }
        curBoard.updateBoard(curBoard, attackRow, attackCol);
        if (curBoard.isShipDestroyed(currentShip)) {
            cout << prevPlayer.getName() << " destroyed " << curPlayer.getName()
                 << "'s " << currentShip << "!" << endl<<endl;
            // << endl;
        }
        else{
            cout<<endl;
        }
        if (curBoard.destroy()) {
            //cout<<endl;
            cout << prevPlayer.getName() << " won the game!" << endl;
            win = true;
        }
    } while (!win);

}
