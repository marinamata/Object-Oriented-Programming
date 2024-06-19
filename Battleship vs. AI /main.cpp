
//#include "AI.h"
#include "Board.h"
#include "CheatingAI.h"
#include "Player.h"
#include "RandomAI.h"
#include "playLoop.h"
//#include"SearchAndDestroy.h"
#include <algorithm> // hunt and destroy
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <chrono>
#include <vector>
using namespace BattleShip;
using namespace std;

// inside setBoard to check out of bounds and overlap
void HumanPlayers(int choice, int row, int column, vector<string> StringIntMap,
                  playLoop game, std::mt19937&generator) {
    /*Player player1;
    Player player2;

    string r1, c1;
    player1.setNumber(1);
    cout<<"Player 1 ";
    if(choice == 1){
      player1.inputPlayerDetails();
    }


    Board b1;
    b1.setDimensions(row, column);
    b1.showBord();
    string al;
    char alignment;
    int count = 0;
    int b = StringIntMap.size()-1;
    for (int i = 3; i <StringIntMap.size(); i += 2) {
        cout << player1.getName()
             << ", do you want to place "<<StringIntMap.at(i)<<" horizontally or
    vertically?"<<endl; cout << "Enter h for horizontal or v for vertical" <<
    endl; cout << "Your choice: ";
        // cin>>al;
        getline(cin, al);

        bool valid = game.isValid(al);//check alignment input is valid or not
        if (!valid) {
            i -= 2;
            continue;
        }
        alignment = al.at(0);


        cout <<player1.getName()<< ", enter the row and column you want to place
    "<<StringIntMap.at(i)<<", which is "<<StringIntMap.at(i+1)<<" long, at with a
    space in between row and col:"; cin >> r1 ;


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
        //string placer;
        //getline(cin, placer);


        char name = StringIntMap.at(i).at(0);

        bool checkSet =//check overlap and out of bounds
                b1.setBoard(stoi(r1), stoi(c1), alignment, name,
    stoi(StringIntMap.at(i + 1))); if (!checkSet) { i -= 2; string placer;
            getline(cin, placer);

            continue;
        }

    }


    // Player 2 Creation
    string placer;
    getline(cin, placer);


    player2.setNumber(2);
    cout<<"Player 2 ";
    if(choice == 1){
      player2.inputPlayerDetails();
    }
    else if(choice == 2){
      int settingAnswer;
      cout << "What AI do you want?" <<endl;
      cout << "1. Cheating AI" << endl;
      cout << "2. Random AI" << endl;
      cout << "3. Hunt Destroy AI" << endl;
      cout << "Your choice: ";
      cin>>settingAnswer;
      if(settingAnswer == 1){
        CheatingAI player22(row, column);
        player22.setName("AI Player 1");
        player22.setNumber(1);
        player22.setBoard(row, column, StringIntMap, generator);

      }
      else if(settingAnswer == 2){
        RandomAI player22(row, column);
        player22.setName("AI Player 1");
        player22.setNumber(1);
        player22.getNextIndex();
      }

    }
    else */
    if (choice == 3) {
        int settingAnswer;
        int settingAnswer2;
        CheatingAI player1(row, column);
        RandomAI player11(row, column);
        CheatingAI player2(row, column);
        RandomAI player22(row, column);
        Board b1;
        Board b2;
        int player1Num;
        int player2Num;
        cout << "What AI do you want?" << endl;
        cout << "1. Cheating AI" << endl;
        cout << "2. Random AI" << endl;
        cout << "3. Hunt Destroy AI" << endl;
        cout << "Your choice: ";
        cin >> settingAnswer;
        if (settingAnswer == 1) {
            player1.setName("AI 1");
            player1.setNumber(1);
            player1.setBoard(row, column, StringIntMap, generator);
            b1 = player1.getBoard();
            player1Num = 1;

        } else if (settingAnswer == 2) {

            player11.setName("AI 1");
            player11.setNumber(1);
            player11.setBoard(row, column, StringIntMap, generator);
            b1 = player11.getBoard();
            player1Num = 2;
        } else if (settingAnswer == 3) {
            // TODO
        }

        cout << "What AI do you want?" << endl;
        cout << "1. Cheating AI" << endl;
        cout << "2. Random AI" << endl;
        cout << "3. Hunt Destroy AI" << endl;
        cout << "Your choice: ";
        cin >> settingAnswer2;
        if (settingAnswer2 == 1) {

            player2.setName("AI 2");
            player2.setNumber(2);
            player2.setBoard(row, column, StringIntMap, generator);
            b2 = player2.getBoard();
            player2Num = 1;
        } else if (settingAnswer2 == 2) {

            player22.setName("AI 2");
            player22.setNumber(2);
            player22.setBoard(row, column, StringIntMap, generator);
            b2 = player22.getBoard();
            player2Num = 2;
        } else if (settingAnswer2 == 3) {
            // TODO
        }
        if (settingAnswer == 1 && settingAnswer2 == 1) {
            game.runLoop(player1, player2, b1, b2, row, column, generator);
        }
        else if (settingAnswer == 2 && settingAnswer2 == 1)     {
            game.runLoop(player11, player2, b1, b2,row, column,generator);
        }
        else if (settingAnswer == 1 && settingAnswer2 == 2)     {
            game.runLoop(player1, player22, b1, b2,row, column,generator);
        }
        // run
    }

    /*string r2,c2;


    Board b2;//board for player 2
    b2.setDimensions(row, column);//makes the board
    b2.showBord();
    string al2;
    char alignment2;


    for (int i = 3;i<StringIntMap.size(); i += 2) {
        cout << player2.getName()
             << ", do you want to place "<<StringIntMap.at(i)<<" horizontally or
    vertically?"<<endl; cout << "Enter h for horizontal or v for vertical" <<
    endl; cout << "Your choice: ";
        //cin >> al2;
        getline(cin, al2);

        bool valid = game.isValid(al2);//check alignment input is valid or not
        if (!valid) {
            i -= 2;
            continue;
        }
        alignment2 = al2.at(0);//change string to int
        cout <<player2.getName()<< ", enter the row and column you want to place
    "<<StringIntMap.at(i)<<", which is "<<StringIntMap.at(i+1)<<" long, at with a
    space in between row and col:"; cin >> r2; if (!game.isNumber(r2,row) ) { i -=
    2; string placer2; getline(cin, placer2); continue;
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
                b2.setBoard(stoi(r2), stoi(c2), alignment2, name,
    stoi(StringIntMap.at(i + 1))); if (!checkSet) {

            i -= 2;
            string placer2;
            getline(cin, placer2);
            continue;
        }
    }*/
}

int main(int argc, char **argv) { // get the file
    vector<string> StringIntMap;
    ifstream in(argv[1]); // open files
    int seed;
    if ((argv[2] != nullptr)) {
        seed = atoi(argv[2]);
    }else{
        seed = std::chrono::system_clock::now().time_since_epoch().count();
    }
    //cout<<seed;
    std::mt19937 generator(seed);

    string text; // reads the file
    while (in >> text) {
        StringIntMap.push_back(text);
    }

    /*
    string temp;
    temp = StringIntMap.at(3 );
    StringIntMap.at(3) = StringIntMap.at(5 );
    StringIntMap.at(5) =temp;*/

    // char boad1[7][7];
    // char board2[7][7];
    playLoop game = playLoop();
    int row = stoi(StringIntMap.at(0));
    int column = stoi(StringIntMap.at(1));

    // Player 1 Creation

    int menuAnswer;
    int settingAnswer;
    cout << "What type of game do you want to play?\n"
            "1. Human vs Human\n"
            "2. Human vs AI\n"
            "3. AI vs AI\n"
            "Your choice: ";
    cin >> menuAnswer;
    //int seed = -25;

    HumanPlayers(menuAnswer, row, column, StringIntMap, game, generator);

    /*AIPlayer bot;
    bot.setBoard(row, column, StringIntMap, generator);
    for(int i =0;i<10;i++){
    int lmfao = bot.getAImove(generator);
    cout<<lmfao<<endl;
      }*/
}
