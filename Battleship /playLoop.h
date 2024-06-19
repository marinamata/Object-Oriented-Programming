//
// Created by Marina Mata on 5/9/22.
//

#ifndef BATTLESHIP_PLAYLOOP_H
#define BATTLESHIP_PLAYLOOP_H

#include<string>
#include"Player.h"
#include"Board.h"
using namespace std;
namespace BattleShip {
    class playLoop {
    public:
        bool isValid(string str);

        bool isNumber(const string &str, int limit);

        void runLoop(Player player1, int row, int column, Board b1, Player player2, Board b2);

    private:
        int row;
        int col;

    };


#endif //BATTLESHIP_PLAYLOOP_H
}