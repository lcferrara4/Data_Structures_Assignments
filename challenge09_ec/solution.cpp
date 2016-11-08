// Challenge 9 Extra Credit: Graph Partitioning
#include <iostream>
#include <cctype>
#include <vector>
#include <set>

using namespace std;

set<int> checkConnections(int, vector<vector<int>>&, int, set<int>);

// Main Execution

int main(int argc, char *argv[]) {

    int NVERT;
    int timesLoop = 0;

    while( cin >> NVERT ){
        if( timesLoop != 0 ){
            cout << endl;
        }
        timesLoop++;

        vector<vector<int>> adjMat;
        vector<char> vert;

        char vertex;

        for( int i = 0; i < NVERT; i++ ){
            cin >> vertex;
            vert.push_back(vertex);
        }

        int val;
        for( int i = 0; i < NVERT; i ++ ){
            adjMat.push_back(vector<int> ());
            for( int j = 0; j < NVERT; j++ ){
                cin >> val;
                adjMat[i].push_back(val);
            }
        }

        set<int> allVert;
        set<int> connect;
        
        int count = 0;

        // check for connections
        while( allVert.size() < NVERT ){
            if( count != 0 ){
                cout << endl;
            }
            while( allVert.find(count) != allVert.end() ){
                count++;
            }
            connect = checkConnections(NVERT, adjMat, count, connect);
            allVert.insert(connect.begin(), connect.end());
            // print
            auto tempIT = connect.begin();
            for( auto it = connect.begin(); it != connect.end(); ++it ){
                tempIT = it;
                tempIT++;
                if ( tempIT == connect.end() )
                    cout << vert[*it] << endl;
                else
                    cout << vert[*it] << " ";
            }
            // print columns:
            for( auto it = connect.begin(); it != connect.end(); ++it ){
                tempIT = connect.begin();
                for( auto t = connect.begin(); t != connect.end(); ++t ){
                    tempIT = t;
                    tempIT++;
                    if( tempIT == connect.end() )
                        cout << adjMat[*it][*t] << endl;
                    else    
                        cout << adjMat[*it][*t] << " ";
                }
            }
            count++;
            connect.clear();
            
        }
    }


    return EXIT_SUCCESS;
}

set<int> checkConnections(int NVERT, vector<vector<int>> &adjMat, int col, set<int> connect){
    connect.insert(col);
    set<int> temp;

    for( int i = 0; i < NVERT; i++ ){
        if( adjMat[i][col] == 1 && connect.find(i) == connect.end()){
            connect.insert(i);
            temp = checkConnections(NVERT, adjMat, i, connect);
            connect.insert(temp.begin(), temp.end());
        }
    }

    return connect;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
