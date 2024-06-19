//
// Created by Marina Mata on 5/22/22.
//

#include "HuntDestroy.h"
#ifndef HDAI_PLAYER_H
#define HDAI_PLAYER_H

#include<iostream>
#include "Board.h"
#include "RandomAI.h"
using namespace std;
namespace BattleShip{
    class HuntDestroyAI : public RandomAI{
    private:
        int row;
        int col;
        int nextIndex[2];
        struct Locations{
            int r;
            int c;
            bool mode;
        };
        vector<Locations> locations;


    public:
        HuntDestroyAI(int rows, int cols);
        int* getNextIndex();
        int getAttack(std::minstd_rand& generator);
    };
}
#endif //CAI_PLAYER_H
