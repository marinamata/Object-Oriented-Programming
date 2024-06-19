//
// Created by Marina Mata on 5/22/22.
//
//
// Created by Marina Mata on 5/20/22.
//

#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H


namespace BattleShip {
    class Board{
    private:
        int rows;
        int cols;
        char** board;
    public:
        void setDimensions(int, int);
        bool setBoard(int, int,char, char, int);
        void updateBoard(Board,int, int);
        char** getBoard();
        void showBord();
        bool checkHit(int, int);
        char getValue(int, int);
        bool destroy();
        bool isShipDestroyed(char);
    };
}

#endif //UNTITLED_BOARD_H
