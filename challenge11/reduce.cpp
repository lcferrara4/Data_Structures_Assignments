// reduce.cpp: inverted index
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
using namespace std;

void printWord(string, priority_queue<int, std::vector<int>, std::greater<int> > &);

int main(int argc, char *argv[]) {

    string word, next_word;
    int lineNo, lastNo;
    priority_queue<int, std::vector<int>, std::greater<int> > numbers;

    word = ""; lastNo = 0;
    while(cin >> next_word){
        cin >> lineNo;
        if( next_word != ""){
            if( word == next_word ){
                if( lastNo != lineNo )
                    numbers.push(lineNo);        
            } else{
                printWord(word, numbers);
                numbers.push(lineNo);
            }
        }
        word = next_word; lastNo = lineNo;
    }
    printWord(word, numbers);
    return EXIT_SUCCESS;
}

void printWord(string word, priority_queue<int, std::vector<int>, std::greater<int> >& q) {
    bool first = 1;
    if( word != ""){
        cout << word << "\t";
        while(!q.empty()){
            if( !first )
                cout << " " << q.top();
            else{
                cout << q.top();
                first = 0;
            }
            q.pop();
        }
        cout << endl;
    }
}
// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
