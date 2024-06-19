#include <iostream>
#include <string>
#include <chrono>

#include "play.h"

//using namespace std;
//char getInputs();
//char getComputerMove(std::minstd_rand& generator);

//argc = number of command line arguments
//argv = list of the arguments

int main(int argc, char *argv[]) {
    int seed;
   if(argc >1) {
        seed = atoi(argv[1]);
    }
    else{
        seed = std::chrono::system_clock::now().time_since_epoch().count();
    }
    std::minstd_rand generator(seed);

    char computer;
    char humanMove;
    char b = 'y';
    while(b!='n') {
        //int seed = std::chrono::system_clock::now().time_since_epoch().count();
         humanMove = getInputs();
        computer = getComputerMove(generator);

        comparisonOutcomes(computer, humanMove,  generator);
        b = AskReplay();




    }
    return 0;
}



