// Challenge 04: Card Rank

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Card{
    string name;
    int rank;
    int suit;
};

int convertRank(string);
int convertSuit(char);

bool Compare(const Card& a, const Card& b){

    if (a.rank == b.rank){       
        return a.suit > b.suit;
    } else{
        return a.rank > b.rank;
    }
}

// Main Execution

int main(int argc, char *argv[]) {
    vector<Card> cards;

    int N;    
    string name;
    string rank;
    char suit;

    Card newCard;

    cin >> N;
    // get input
    while (N >= 0){
        for( int i = 0; i < N; i++ ){
            cin >> name;
            cin >> rank;
            cin >> suit;
            newCard = {name, convertRank(rank), convertSuit(suit)};
            cards.push_back(newCard);
        }
         
        // sort
        sort( cards.begin(), cards.end(), Compare ); 

        // output
        for( int i = 0; i < N - 1; i++){
            cout << cards[i].name << ", ";
        }
        cout << cards[N-1].name << endl;

        // start over
        cards.clear();
        cin >> N;
    }
    return EXIT_SUCCESS;
}

// Functions

int convertRank(string rank){
    int r;
    
    if(isdigit(rank[0])){
        r = stoi(rank);
    } else{
        switch(rank[0]){
            case 'J':
                r = 11;
                break;
            case 'Q':
                r = 12;
                break;
            case 'K':
                r = 13;
                break;
            case 'A':
                r = 14;
                break;
        }
    }

    return r;
}

int convertSuit(char suit){
    int s;
    switch(suit){
        case 'C':
            s = 1;
            break;
        case 'D':
            s = 2;
            break;
        case 'H':
            s = 3;
            break;
        case 'S':
            s = 4;
            break;
    }
    return s;
}


// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
