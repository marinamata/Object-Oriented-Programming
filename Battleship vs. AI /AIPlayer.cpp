//
// Created by Marina Mata on 5/22/22.
//

#include "AIPlayer.h"
//
// Created by Marina Mata on 5/20/22.
//

#include "AIPlayer.h"
#include<iostream>
#include <string>
#include "AIPlayer.h"
using namespace BattleShip;
using namespace std;

void AIPlayer::setBoard(int row, int column,vector<string> StringIntMap,std::mt19937& generator){


    board.setDimensions(row, column);
    //cout<<StringIntMap.size();
    for (int i = 3;i<StringIntMap.size(); i += 2) { //created the AI board

        alignment = getOrientation(generator);
        //cout<<alignment<<endl;
        string b = StringIntMap.at(i+1);
        char le = b.at(0) ;
        int length = stoi(b);
        int r = getRow(generator, row,alignment,length);
        //cout<<"Coordintaes"<<endl<<r<<endl;
        int c = getCol(generator, column,alignment,length);
        //cout<<c<<endl;


        string a = StringIntMap.at(i);
        char name = a.at(0) ;

        bool checkSet =//check overlap and out of bounds
                board.setBoard(r, c, alignment, name, stoi(StringIntMap.at(i + 1)));
        if (!checkSet) {
            i -= 2;
            continue;
        }
        if(checkSet){
            cout<<this->getName()<<"\'s Board"<<endl;
            board.showBord();
            cout<<endl;
        }

    }

    //Place all ships in the AI board
    //put the random generator

    //board.showBord();
}

void AIPlayer::inputFireIndex(){

}
char AIPlayer::getOrientation(std::mt19937& generator){

    int number = getRandomInt(0,1, generator);
    if(number==0){
        return 'h';
    }else{
        return 'v';
    }
}
int AIPlayer::getRow(std::mt19937& generator, int row,char alignment, int length){
    int a;
    if(alignment=='h') {
        a = getRandomInt(0, row - 1, generator);
    }else{
        a = getRandomInt(0, row -length, generator);
    }
    return a;
}
int AIPlayer::getCol(std::mt19937& generator, int col,char alignment,int length){
    int b;
    if(alignment=='v') {
        b = getRandomInt(0, col - 1, generator);
    }else{
        b = getRandomInt(0, col -length, generator);
    }
    return b;
    // std::uniform_int_distribution<int> dist(0,col-1);
    //return dist(generator);
    //return getRandomInt(0,col-1, generator);
}
