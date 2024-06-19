//
// Created by Marina Mata and Leo Yang on 4/14/22.
#include <iostream>
#include <random>
#include"play.h"
#include<algorithm>
#include<string>


char getInputs() {
    std::string humanMove;
    char x;
    std::cout << "Enter (R)ock, (P)aper, or (S)cissors for your move: ";
    std::getline(std::cin, humanMove);
    transform(humanMove.begin(), humanMove.end(), humanMove.begin(),::tolower);




    while (humanMove != "r" && humanMove != "p" && humanMove != "s" && humanMove != "(r)ock" && humanMove != "rock" && humanMove != "(p)aper" && humanMove != "paper" && humanMove != "(s)cissors" && humanMove != "scissors"&&
    humanMove != "R" && humanMove != "P" && humanMove != "S" && humanMove != "(R)ock" && humanMove != "Rock" && humanMove != "(P)aper" && humanMove != "Paper" && humanMove != "(S)cissors" && humanMove != "Scissors") {
        std::cout << "Enter (R)ock, (P)aper, or (S)cissors for your move: ";

        std::getline(std::cin, humanMove);
        transform(humanMove.begin(), humanMove.end(), humanMove.begin(),::tolower);


    }


    if (humanMove == "(r)ock") {
        x = 'r';
    }
    if (humanMove == "rock") {
        x = 'r';
    }
    if (humanMove == "Rock") {
        x = 'r';
    }
    if (humanMove == "(p)aper") {
        x = 'p';
    }
    if (humanMove == "paper") {
        x = 'p';
    }
    if (humanMove == "Paper") {
        x = 'p';
    }
    if (humanMove == "(s)cissors") {
        x = 's';
    }
    if (humanMove == "scissors") {
        x = 's';
    }
    if (humanMove == "Scissors") {
        x = 's';
    }
    if (humanMove == "r") {
        x= 'r';
    }
    if (humanMove == "p") {
        x = 'p';
    }
    if (humanMove == "s") {
        x = 's';
    }if (humanMove == "(R)ock") {
        x = 'r';
    }
    if (humanMove == "R") {
        x = 'r';
    }

    if (humanMove == "(P)aper") {
        x = 'p';
    }
    if (humanMove == "P") {
        x = 'p';
    }

    if (humanMove == "(S)cissors") {
        x = 's';
    }

    if (humanMove == "S") {
        x = 's';
    }



    return x;
}


// function to get Random int // get an integer between min and max
/*template<typename RandomNumberGenerator>
int getRandomInt(int min, int max, RandomNumberGenerator& rng){
    std:: uniform_int_distribution<int> dist(min,max);
    int random_num = dist(rng);
    return random_num;

}*/
/*int getNumber(int seed){
    std::minstd_rand generator(seed);
    int y = getRandomInt(0,2, generator);
    return y;
}*/
//function to get move from the computer use random generator to return a move //everytime I call the function, you make a new generator

char getComputerMove(std::minstd_rand& generator) {
    //ERROR!!, always returning the min value// FIX
    //std::minstd_rand generator(seed);
    int y = getRandomInt(0,2, generator);
    if( y == 0){
        std::cout<< "The ai played rock."<<std::endl;
        return 'r';
    }
    else if( y == 1){
        std::cout<< "The ai played paper."<<std::endl;
        return 'p';
    }
    else if( y == 2) {
        std::cout << "The ai played scissors." << std::endl;
        return 's';
    }
    return 0;
}
/*char getComputerMove2(int seed) {
    //ERROR!!, always returning the min value// FIX
    std::minstd_rand generator(seed);
    int y = getRandomInt(0,2, generator);
    if( y == 0){
        std::cout<< "The ai played rock."<<std::endl;
        return 'r';
    }
    else if( y == 1){
        std::cout<< "The ai played paper."<<std::endl;
        return 'p';
    }
    else if( y == 2) {
        std::cout << "The ai played scissors." << std::endl;
        return 's';
    }
    return 0;
}*/
//function to compare all moves
void comparisonOutcomes( char computer, char humanMove, std::minstd_rand& generator) {
    //std::minstd_rand generator(seed);
    if (computer == 'r' && humanMove == 'r') {
        std::cout << "You and the AI both played rock." << std::endl;
        std::cout << "Keep playing until someone wins." << std::endl;
        char a = getInputs();
        char b = getComputerMove(generator);
        comparisonOutcomes(b,a,generator);
    } else if (computer == 'r' && humanMove == 'p') {
        std::cout << "You win!" << std::endl;
    } else if (computer == 'r' && humanMove == 's') {
        std::cout << "The AI wins :(" << std::endl;
    } else if (computer == 'p' && humanMove == 'r'){

        std::cout << "The AI wins :(" << std::endl;
    } else if (computer == 'p' && humanMove == 'p') {
        std::cout << "You and the AI both played paper." << std::endl;
        std::cout << "Keep playing until someone wins." << std::endl;
        char a = getInputs();
        char b = getComputerMove( generator);
        comparisonOutcomes(b,a,generator);
    } else if (computer == 'p' && humanMove == 's') {
        std::cout << "You win!" << std::endl;
    } else if (computer == 's' && humanMove == 's') {
        std::cout << "You and the AI both played scissors." << std::endl;
        std::cout << "Keep playing until someone wins." << std::endl;
        char a = getInputs();
        char b = getComputerMove(generator);
        comparisonOutcomes(b,a,generator);
    } else if (computer == 's' && humanMove == 'r') {
        std::cout << "You win!" << std::endl;
    } else if (computer == 's' && humanMove == 'p') {
        std::cout << "The AI wins :(" << std::endl;
    }

}
char AskReplay(){
    std::string humanMove;
    char x;
    std::cout<<"Would you like to replay the game?"<<std::endl;
    std::cout<<"Enter (Y)es or (N)o: ";
    std::getline(std::cin, humanMove);
    transform(humanMove.begin(), humanMove.end(), humanMove.begin(),::tolower);
    while (humanMove != "y" && humanMove != "yes" && humanMove != "(y)es" && humanMove != "Y" && humanMove != "Yes" && humanMove != "(Y)es" && humanMove != "no" && humanMove != "n" && humanMove != "(n)o"&& humanMove != "No" && humanMove != "N" && humanMove != "(N)o") {
        std::cout<<"Would you like to replay the game?"<<std::endl;
        std::cout<<"Enter (Y)es or (N)o: ";
        std::cin >> humanMove;

    }


    if (humanMove == "yes") {
        x = 'y';
    }
    if (humanMove == "y") {
        x = 'y';
    }
    if (humanMove == "(y)es") {
        x = 'y';
    }
    if (humanMove == "Yes") {
        x = 'y';
    }
    if (humanMove == "Y") {
        x = 'y';
    }
    if (humanMove == "(Y)es") {
        x = 'y';
    }
    if (humanMove == "no") {
        x = 'n';
    }
    if (humanMove == "n") {
        x = 'n';
    }
    if (humanMove == "(n)o") {
        x = 'n';
    }
    if (humanMove == "No") {
        x = 'n';
    }
    if (humanMove == "N") {
        x = 'n';
    }
    if (humanMove == "(N)o") {
        x = 'n';
    }
    return x;




}


