//
// Created by Marina Mata on 5/22/22.
//

//
// Created by Marina Mata on 5/20/22.
//

#ifndef UNTITLED_HUMANPLAYER_H
#define UNTITLED_HUMANPLAYER_H


#include<iostream>
#include "Board.h"
#include "Player.h"
using namespace std;

namespace BattleShip{
    class HumanPlayer : public Player {
    public:
        void setBoard(int row, int column);
        Board getBoard();
        void inputFireIndex();
        HumanPlayer()=default;
    private:
        Board board;
        char alignment;
        string r1, c1;
    };
}


#endif //UNTITLED_HUMANPLAYER_H
