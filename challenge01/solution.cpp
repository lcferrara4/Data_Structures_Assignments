// Challenge 01: Rotating Arrays

#include <string>
#include <iostream>
#include <deque>
#include <stdio.h>

using namespace std;

// Main Execution

int main(int argc, char *argv[]) {

    string line;
    string size;
    string numRot;
    string dir;
    string num;

    deque<int> dq;
    
    while (getline(cin, size, ' ')){

        // Get parameters
        getline(cin, numRot, ' ');
        getline(cin, dir);

        // Fill deque with values
        for (int i = 0; i < stoi(size) - 1; i++)
        {
            getline(cin, num, ' ');
            dq.push_back(stoi(num));
        }
        getline(cin, num);
        dq.push_back(stoi(num));
 
        // Rotations
        for (int i = 0; i < stoi(numRot); i++){
            if ( dir.compare("L") == 0 ){
                int value = dq.front();
                dq.pop_front();
                dq.push_back(value);
            }
            else{
                int value = dq.back();
                dq.pop_back();
                dq.push_front(value);
            }
        }

        // Print
        for (int i = 0; i < stoi(size) - 1; i++){
            cout << dq.at(i) << " ";
        }             
        cout << dq.at(stoi(size) - 1) << endl;

        dq.clear();
    }
    return 0;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
