// Challenge 09: Graph Paths

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>

using namespace std;

bool hasPath( map<char, vector<char>> &, char, char );

// Main Execution

int main(int argc, char *argv[]) {

    int NEDGES;
    int NPATHS;
    char SRC;
    char DST;
    int numGraph = 0;

    map<char, vector<char>> adjList;

    while( cin >> NEDGES ){
        
        if( numGraph != 0 ){
            cout << endl;
        }
        
        numGraph++;

        for( int i = 0; i < NEDGES; i++ ){
            cin >> SRC;
            cin >> DST;
            
            if( adjList.find(SRC) != adjList.end() ){
                adjList[SRC].push_back(DST);
            } else{
                adjList[SRC] = {DST};
            }
        }
 
        cin >> NPATHS;
    
        for( int i = 0; i < NPATHS; i++ ){
            cin >> SRC;
            cin >> DST;
            
            if( hasPath(adjList, SRC, DST) ){
                cout << "In Graph " << numGraph << " there is a path from "<< SRC <<" to "<< DST << endl;
            } else{
                cout << "In Graph " << numGraph << " there is no path from "<< SRC <<" to "<< DST << endl;
            }
        }
    
        adjList.clear();
    }
    

    return EXIT_SUCCESS;
}

bool hasPath(map<char, vector<char>> &g, char src, char dst){

    stack<char> q;
    set<char>   v;
    q.push(src);
    v.insert(src);
    char temp;

    while(!q.empty()){
        temp = q.top();
        q.pop();
        
        for( auto it = g[temp].begin(); it != g[temp].end(); ++it ){
            if (*it == dst){
                return true;
            } else{
                if( v.find(*it) == v.end() ){
                    q.push(*it);
                    v.insert(*it);
                }
            }
        }
    }

    return false;
}


// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
