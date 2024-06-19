//
// Created by Marina Mata on 5/20/22.
//

#ifndef UNTITLED_PLAYLOOP_H
#define UNTITLED_PLAYLOOP_H


#include <algorithm>
#include <random>
#include<string>
#include"Board.h"
#include "RandomAI.h"
#include "CheatingAI.h"
using namespace std;
namespace BattleShip {
    class playLoop {
    public:
        bool isValid(string str);

        bool isNumber(const string &str, int limit);

        void runLoop(RandomAI player1, CheatingAI player2, Board b1, Board b2, int row, int column,std::mt19937& generator);
        void runLoop(CheatingAI player1, RandomAI player2, Board b1, Board b2, int row, int column,std::mt19937& generator);
        void runLoop(CheatingAI player1, CheatingAI player2, Board b1, Board b2, int row, int column,std::mt19937& generator);

    private:
        int row;
        int col;

    };
}
#endif //UNTITLED_PLAYLOOP_H
