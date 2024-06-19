//
// Created by Marina Mata on 5/20/22.
//

#ifndef UNTITLED_RANDOMAI_H
#define UNTITLED_RANDOMAI_H

#include<iostream>
#include "Board.h"
#include "AIPlayer.h"
using namespace std;
namespace BattleShip{
    class RandomAI : public AIPlayer{
    private:
        int row;
        int col;
        int nextIndex[2];
        struct Locations{
            int r;
            int c;
        };
        vector<pair<int,int>> locations;


    public:
        RandomAI(int rows, int cols);
        int* getNextIndex();
        pair<int, int> getAttack(std::mt19937& generator);
    };

}


#endif //UNTITLED_RANDOMAI_H
