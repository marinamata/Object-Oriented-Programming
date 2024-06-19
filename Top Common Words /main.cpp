
// Created by Marina Mata on 4/20/22.

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>
#include "CommonWords.h"
using namespace std;

//we need a function that prints out the top n most common words
//we need a function that deletes the extra characters !@#$$%%^&
int main(int argc, char **argv) {

    map<std::string, int> StringIntMap;

    ifstream in(argv[1]);
    int number = 0;
    if((argv[2] != nullptr)){

        number = atoi(argv[2]);

    }

    //StringIntMap words_map;
    check_strings(in, StringIntMap);
    deleteWords(StringIntMap);
    map<int, string> sorted = reverseMap(StringIntMap);
    /*for (map<int, string>::reverse_iterator it = sorted.rbegin(); it != sorted.rend(); ++it) {
        cout << " These words appeared " << it->second << " times: {" << it->first << "}" << endl;
    }*/
    printFrequency(number,sorted,StringIntMap);


}