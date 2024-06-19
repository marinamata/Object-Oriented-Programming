//
// Created by Marina Mata on 5/22/22.
//

//
// Created by Marina Mata on 5/20/22.
//

#ifndef UNTITLED_AIPLAYER_H
#define UNTITLED_AIPLAYER_H


#ifndef AI_PLAYER_H
#define AI_PLAYER_H
#include<iostream>
#include "Board.h"
#include <random>
#include "Player.h"
#include <vector>
using namespace std;

namespace BattleShip{
    class AIPlayer : public Player {
    public:

        void setBoard(int row, int column,vector<string> StringIntMap, std::mt19937& generator);
        //Board getBoard();

        void inputFireIndex();
        template<typename RandomNumberGenerator>
        int getRandomInt(int min, int max, RandomNumberGenerator& rng){
            std:: uniform_int_distribution<int> dist(min,max);
            int random_num = dist(rng);
            return random_num;
        }
        char getOrientation(std::mt19937& generator);
        int getAImove(std::mt19937& generator);
        int getRow(std::mt19937& generator, int row, char alignment, int length);
        int getCol(std::mt19937& generator, int col,char alignment, int length);
        AIPlayer()=default;
    private:

        char alignment;
        string r1, c1;
    };
}
#endif //HUMAN_PLAYER_H

#endif //UNTITLED_AIPLAYER_H
