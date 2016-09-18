// Challenge 03: Closest Numbers

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

// Main Execution

int main(int argc, char *argv[]) {

    string num;
    int N;

    string temp;
    vector<int> A;
    vector<int> D;

    int smallest_diff;

    while(getline(cin, num)){
       
        // get number of elements
        N = stoi(num);
       
        // fill vector with elements 
        for( int i = 0; i < N - 1; i++ ){
            getline(cin, temp, ' ');
            A.push_back(stoi(temp));
        }
        getline(cin, temp);
        A.push_back(stoi(temp));
        
        // sort
        sort(A.begin(), A.end());
        
        // find differences
        smallest_diff = INT_MAX;
        for( int i = 0; i < N - 1; i++ ){
            if( abs( A[i] - A[i+1] ) <= smallest_diff ){
                if( abs( A[i] - A[i+1] ) < smallest_diff )
                    D.clear();
                smallest_diff = abs( A[i] - A[i+1] );
                D.push_back(A[i]);
                D.push_back(A[i+1]);
            }
        }
      
        // print elements with smallest diffs 
        size_t i; 
        for( i = 0; i < D.size() - 1; i++ ) {
            cout << D[i] << " ";
        }
        cout << D[i] << endl;

        // clear vector
        A.clear();
    }

    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
