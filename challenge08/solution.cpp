// Challenge 08: Palindrome Permutation
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cctype>

// Main Execution

using namespace std;

string removeSpacePunc(string);
int getOddCount(unordered_map<char, int>);

int main(int argc, char *argv[]) {

    string input;
    string phrase;
    unordered_map<char, int> letters;

    int odd;

    while( getline(cin, input) ){
       
        phrase = removeSpacePunc(input);
 
        for( size_t i = 0; i < phrase.length(); i++ ){
            if( letters.find(phrase[i]) != letters.end() ){
                letters[phrase[i]] += 1;
            } else{
                letters.insert({phrase[i], 1});
            }
        }

        odd = getOddCount(letters);

        if( odd == 1 || odd == 0 ){
            cout << "\"" << input << "\" is a palindrome permutation" << endl;
        } else{
            cout << "\"" << input << "\" is not a palindrome permutation" << endl;
        }

        letters.clear();
    }

    return EXIT_SUCCESS;
}

string removeSpacePunc( string phrase ){

    string new_string = "";

    for( size_t i = 0; i < phrase.length(); i++ ){
        if( isalnum(phrase[i])){
            new_string += phrase[i];
        }
    }
    
    return new_string;
}

int getOddCount(unordered_map<char, int> dict){
    int count = 0;
   
    for (auto& x: dict){
        if ( x.second % 2 != 0 ){
            count++;
        }
    }
    return count;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
