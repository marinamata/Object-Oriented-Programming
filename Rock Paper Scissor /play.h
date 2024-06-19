//
// Created by Marina Mata on 4/14/22.
//

#ifndef ROCKPAPERSCISSORS_PLAY_H
#define ROCKPAPERSCISSORS_PLAY_H
#include <random>
#include <iterator>
#include <vector>
#include <ostream>
#endif //ROCKPAPERSCISSORS_PLAY_H
//header has all the definitions
char getComputerMove(int seed);
char getInputs();
template<typename RandomNumberGenerator>
int getRandomInt(int min, int max, RandomNumberGenerator& rng){
    std:: uniform_int_distribution<int> dist(min,max);
    int random_num = dist(rng);
    return random_num;

}
int getNumber(int seed);
char getComputerMove(std::minstd_rand& generator);
//char getComputerMove2(int seed);
void comparisonOutcomes( char computer, char humanMove,std::minstd_rand& generator);
char AskReplay();
