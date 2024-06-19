//
// Created by Marina Mata on 5/20/22.
//

#include "RandomAI.h"
#include "RandomAI.h"
#include <vector>
using namespace BattleShip;
using namespace std;
RandomAI::RandomAI(int rows, int cols){
    row = rows;
    col = cols;
    for(int i =0;i<row;i++){
        for(int j=0;j<col;j++){
            locations.push_back(make_pair(i,j));
        }
    }
    //nextIndex[0] = 0;
    //nextIndex[1] = 0;
}

pair<int , int > RandomAI::getAttack(std::mt19937& generator){

    //vector<pair<int,int>> attack;


    int element;
    // for(int i =0;i<10;i++) {
    element = getRandomInt(0, locations.size()-1, generator);
    pair<int,int> placer = locations.at(element);
    locations.erase(locations.begin() + element);
    // }
    return placer;
    //return locations.at(element);
}
//
// Created by Marina Mata on 5/22/22.
//

#include "RandomAI.h"
