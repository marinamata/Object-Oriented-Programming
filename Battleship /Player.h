//
// Created by Marina Mata on 5/9/22.
//

#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H


#include<string>
using namespace std;
namespace BattleShip {
    class Player {
    public:
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


#endif //BATTLESHIP_PLAYER_H
