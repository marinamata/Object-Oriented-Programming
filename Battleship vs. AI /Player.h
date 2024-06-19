//
// Created by Marina Mata on 5/22/22.
//

//
// Created by Marina Mata on 5/20/22.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H


#include "Board.h"
#include<string>
#include <vector>
using namespace std;
namespace BattleShip {
    class Player {

    public:
        Board board;
        Board getBoard();

        string getName();
        void setName(string name);
        int getNumber();
        void setNumber(int number);
        void inputPlayerDetails();
        Player()=default;

    private:
        string name;
        int playerNumber;

    };}

#endif //UNTITLED_PLAYER_H
