//
// Created by Marina Mata on 5/9/22.
//

#include <string>
#include "Player.h"

#include <iostream>

using namespace BattleShip;
using namespace std;

string Player::getName(){
    return name;

}
void Player::setName(string name) {
    this->name=name;

}
int Player::getNumber(){
    return playerNumber;

}
void Player::setNumber(int number) {
    this->playerNumber=number;

}
void Player::inputPlayerDetails(){
    cout<<"please enter your name: ";
    getline (cin, name);
}