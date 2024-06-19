
// Created by Marina Mata on 5/20/22.
//

#ifndef UNTITLED_CHEATINGAI_H
#define UNTITLED_CHEATINGAI_H


#include<iostream>
#include "Board.h"
#include "AIPlayer.h"
using namespace std;
namespace BattleShip{
    class CheatingAI : public AIPlayer{
    private:
        int row;
        int col;
        // int nextIndex[2];
    public:
        CheatingAI(int rows, int cols);
        // int* getNextIndex(int nextIndex[2]);
        vector<int> getCoords(Board a);
    };
}


#endif //UNTITLED_CHEATINGAI_H
