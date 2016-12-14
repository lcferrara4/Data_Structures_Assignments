// map.cpp: inverted index
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>
using namespace std;

string cleanWord(string);

int main(int argc, char *argv[]) {
    string line;
    string word;
    int lineNo = 0;
    while(!cin.eof()){
        getline(cin, line);
        istringstream iss(line);
        lineNo++;
        while(iss >> word){
            word = cleanWord(word);
            if( word != "" )
                cout << word << "\t" << lineNo << endl;
        }
    }    
    return EXIT_SUCCESS;
}

string cleanWord(string word){
    string newWord = "";
    size_t lastChar = 0;
    size_t firstChar = 0;
    for( size_t i = 0; i < word.length(); i++){
        if( isalnum(word[i]) ){
            if( firstChar == 0 )
                firstChar = i; 
            lastChar = i;
        }
    }
    for( size_t i = 0; i < word.length(); i++){
        if( isalnum(word[i]) )
            newWord += tolower(word[i]);
        else if( i > firstChar && i < lastChar  )
            newWord += tolower(word[i]);
    }
    return newWord;
}
// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
