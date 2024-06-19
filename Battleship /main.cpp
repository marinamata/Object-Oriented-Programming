#include "Board.h"
#include "Player.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "playLoop.h"
using namespace BattleShip;
using namespace std;
// inside setBoard to check out of bounds and overlap


int main(int argc, char **argv) { //get the file
    vector<string> StringIntMap;
    ifstream in(argv[1]); // open files
    int number = 0;
    if ((argv[2] != nullptr)) {
        number = atoi(argv[2]);
    }

    string text;        //reads the file
    while (in >> text) {
        StringIntMap.push_back(text);
    }
    string temp;
    temp = StringIntMap.at(3 );
    StringIntMap.at(3) = StringIntMap.at(5 );
    StringIntMap.at(5) =temp;

    // char boad1[7][7];
    // char board2[7][7];
    playLoop game = playLoop();
    int row = stoi(StringIntMap.at(0));
    int column = stoi(StringIntMap.at(1));
    string r1, c1;
    // Player 1 Creation
    Player player1;
    player1.setNumber(1);
    cout<<"Player 1 ";
    player1.inputPlayerDetails();

    Board b1;
    b1.setDimensions(row, column);
    b1.showBord();
    string al;
    char alignment;
    int count = 0;
    int b = StringIntMap.size()-1;
    for (int i = 3; i <StringIntMap.size(); i += 2) {
        cout << player1.getName()
             << ", do you want to place "<<StringIntMap.at(i)<<" horizontally or vertically?"<<endl;
        cout << "Enter h for horizontal or v for vertical" << endl;
        cout << "Your choice: ";
        // cin>>al;
        getline(cin, al);

        bool valid = game.isValid(al);//check alignment input is valid or not
        if (!valid) {
            i -= 2;
            continue;
        }
        alignment = al.at(0);


        cout <<player1.getName()<< ", enter the row and column you want to place "<<StringIntMap.at(i)<<", which is "<<StringIntMap.at(i+1)<<" long, at with a space in between row and col:";
        cin >> r1 ;


        if (!game.isNumber(r1,row)) {
            i-=2;
            string placer;
            getline(cin, placer);
            continue;

        }

        cin>>c1;
        if (!game.isNumber(c1,column)) {
            i-=2;
            string placer;
           getline(cin, placer);
            continue;
        }
        string placer;
        getline(cin, placer);


        char name = StringIntMap.at(i).at(0);

        bool checkSet =//check overlap and out of bounds
                b1.setBoard(stoi(r1), stoi(c1), alignment, name, stoi(StringIntMap.at(i + 1)));
        if (!checkSet) {
            i -= 2;
            string placer;
            getline(cin, placer);

            continue;
        }

    }


    // Player 2 Creation
    /*string placer;
    getline(cin, placer);*/

    Player player2;
    player2.setNumber(2);
    cout<<"Player 2 ";
    player2.inputPlayerDetails();
    string r2,c2;


    Board b2;//board for player 2
    b2.setDimensions(row, column);//makes the board
    b2.showBord();
    string al2;
    char alignment2;


    for (int i = 3;i<StringIntMap.size(); i += 2) {
        cout << player2.getName()
             << ", do you want to place "<<StringIntMap.at(i)<<" horizontally or vertically?"<<endl;
        cout << "Enter h for horizontal or v for vertical" << endl;
        cout << "Your choice: ";
        //cin >> al2;
        getline(cin, al2);

        bool valid = game.isValid(al2);//check alignment input is valid or not
        if (!valid) {
            i -= 2;
            continue;
        }
        alignment2 = al2.at(0);//change string to int
        cout <<player2.getName()<< ", enter the row and column you want to place "<<StringIntMap.at(i)<<", which is "<<StringIntMap.at(i+1)<<" long, at with a space in between row and col:";
        cin >> r2;
        if (!game.isNumber(r2,row) ) {
            i -= 2;
            string placer2;
            getline(cin, placer2);
            continue;
        }
        cin>>c2;
        if (!game.isNumber(c2,column) ) {
            i -= 2;
            string placer2;
            getline(cin, placer2);
            continue;
        }
         string placer2;
         getline(cin, placer2);

        char name = StringIntMap.at(i).at(0);


        bool checkSet =//check overlap and out of bounds
                b2.setBoard(stoi(r2), stoi(c2), alignment2, name, stoi(StringIntMap.at(i + 1)));
        if (!checkSet) {

            i -= 2;
            string placer2;
            getline(cin, placer2);
            continue;
        }
    }
    game.runLoop(player1, row, column, b1, player2, b2);

}

