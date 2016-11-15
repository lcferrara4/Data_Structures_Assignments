// Challenge 10: Minimum Spanning Tree

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

// Main Execution

int main(int argc, char *argv[]) {

    int NVERTICES;
    int turn = 0;
    vector<vector<int>> adjMat;
    int val;    
    
    vector<int> C;
    vector<string> E;
    set<char> Q;

    int letter;
    int totEdge;

    while( cin >> NVERTICES ){
        letter = 65;
    
        // formatting
        if( turn != 0 ){
            cout << endl;
        } 
        turn++;

        // get inputs
        for( int i = 0; i < NVERTICES; i++ ){
            vector<int> temp;
            Q.insert((char)letter);
            C.push_back(-1);
            E.push_back(".");
            for( int j = 0; j < NVERTICES; j++ ){
                cin >> val;
                temp.push_back(val);
            }
            adjMat.push_back(temp);
            letter++;
        }


        char v = 'A';
        while(!Q.empty()){
            // remove vertex from set
            Q.erase(v);
            int count = 0;
            for( auto it = C.begin(); it != C.end(); ++it ){
                // update costs and edges with lower values
                if( adjMat[(int)v - 65][count] != -1 && Q.find((char)(count+65)) != Q.end()){
                    if( *it == -1 || *it > adjMat[(int)v - 65][count] ){
                        // set cost
                        C[count] = adjMat[(int)v - 65][count];
                        // set edge
                        E[count] = "";
                        // check alphabetical order of vertices for edge
                        if( v < count + 65 ){
                            E[count] += v;
                            E[count] += (char)(count + 65);
                        } else{
                            E[count] += (char)(count + 65);
                            E[count] += v;
                        }
                    }
                }   
                count++;
            }
           
            int min = INT_MAX;
            // find next smallest cost to be new vertex v    
            count = 0;
            for( auto it = C.begin(); it != C.end(); ++it ){
                if( *it != -1 && *it < min && Q.find((char)(count+65)) != Q.end() ){
                    min = *it;
                    v = (char)(count + 65);
                }
                count++;
            }
        }

        /* Print Results */
        totEdge = 0;
        
        // Calculate total weights
        for( auto it = C.begin(); it != C.end(); ++it ){
            if( *it != -1 )
                totEdge += *it;
        }
        cout << totEdge << endl;

        // sorts edge names alphabetically
        sort (E.begin(), E.end(), less<string>());

        // print edges
        for( auto it = E.begin(); it != E.end(); ++it ){
            if( *it != "." ) 
                cout << *it << endl;
        }

        C.clear();
        E.clear();
        adjMat.clear();
    }

    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
