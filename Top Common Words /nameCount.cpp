//
// Created by Marina Mata on 4/24/22.
//
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include<vector>
#include <cctype>
#include <algorithm>

using namespace std;



void removeSpecialCharcters(string& str){ //function to remove special characters
    transform(str.begin(), str.end(), str.begin(),::tolower);
    for(int i =0;i<str.size();i++){
        //putchar(tolower(str[i]));
        if((str[i]<'a'||str[i]>'z')&&str[i]!='\''&&(str[i]<'0'||str[i]>'9')){
            str.erase(i,1);
            i--;
        }
    }
    //Printing output.

}
//typedef std::map<std::string, int>StringIntMap; //key is string, int as an integer value
void check_strings(istream &word, map<string,int> & parameters){
    string text;

    //check if word is repeated
    while(word>>text)//read each word in the text
    {
        removeSpecialCharcters(text);// call the function to remove special chars somewhere
        parameters[text]++; // if the word is already in the map, this will increment it's count and add one more
    }

}

void deleteWords(map<string,int>& parameters){
    for(map<string,int>::iterator it = parameters.begin(); it != parameters.end(); ++it)
    {
        if(it->first=="a"||it->first=="an"||it->first=="and"||it->first=="in"||it->first=="is"||it->first=="it"||it->first=="the"){
            parameters.erase(it->first);
        }
    }
}
map<int, string>reverseMap(map<string,int> parameters){
    //vector<string> words;
    map<int, string> sorted;
   // map<int, vector<string>> sorted;
   // for(map<string,int>::iterator it = parameters.begin(); it != parameters.end(); it++)
   // {
     //   int number = it->second;
       // if(it->second==number){
         //   words.push_back(it->first);
//
  //      }
    //}/
    //
    for(map<string,int>::iterator it = parameters.begin(); it != parameters.end(); it++)
    {
        sorted[it->second] = it->first;
    }

    return sorted;

}

void printFrequency(int number, map<int, string> paramaters, map<string, int> map1) {

    if (paramaters.size() < number) {
        for (map<int, string>::reverse_iterator it = paramaters.rbegin(); it != paramaters.rend(); ++it) {
            cout << " These words appeared " << it->first << " times: {";
            /*for(map<string, int>::iterator j = map1.begin(); j != map1.end(); j){

                if(it->first==j->second){
                    cout<<j->first<<"}"<<endl;
                }
            }*/

        }
    } else {
        int count = 0;
        int b = 0;
        int a = 0;

        for (map<int, string>::reverse_iterator it = paramaters.rbegin(); it != paramaters.rend(); ++it) {
            int counter2 =0;
            if (count <= (paramaters.size() - number) - 1) {
                b++;
                cout << b << ".) These words appeared " << it->first << " times: {";

                for(map<string, int>::iterator j = map1.begin(); j != map1.end(); j++){


                    if(it->first==j->second){
                        if(counter2>0){
                        cout << ", ";
                            cout << j->first;//counter2++;
                        }
                        else{
                            cout << j->first;

                        }
                        counter2++;
                    }

                }
                cout<<"}"<<endl;
                count++;
                a++;
                if (a == number) { break; }
            } else {
                count++;
            }
        }

    }

/*map<int,string> reverseMap(map<string,int> parameters){ //int to string// setting in increasing order
    //command line arguments are passed as char " strings" is the word from the file and "int" is the frequency,
    //char* array;
    //if the int/frequecny is the same for multiple words, the you  would print out both strings

    map<int,string> sorted;
    //vector<string>words;//if multiple frequncies then the words with same frequencies stored in vector should be printed
    string a;
    for(map<string,int >::iterator it = parameters.begin(); it != parameters.end(); it++)
    {

        sorted[it->second] = it->first; //it->second is printing the number of times
    }


    return sorted;

}

void printFrequency(int number, map<int, string> paramaters) {

    if (paramaters.size() < number) {
        for (map<int, string>::reverse_iterator it = paramaters.rbegin(); it != paramaters.rend(); ++it) {
            cout << " These words appeared " << it->first << " times: {" << it->second << "}" << endl;
        }
    } else {
        int count = 0;
        int b = 0;
        int a = 0;

        for (map<int, string>::reverse_iterator it = paramaters.rbegin(); it != paramaters.rend(); ++it) {
            if (count <= (paramaters.size() - number) - 1) {
                b++;
                cout << b<<".) These words appeared " << it->first << " times: {" << it->second << "}" << endl;
                count++;
                a++;
                if (a == number) { break; }
            } else {
                count++;
            }
        }
    }  */
}