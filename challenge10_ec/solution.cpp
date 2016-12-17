// Challenge 10 Extra Credit: Hamiltonian Path Problem
#include <iostream>
#define MAXN 20

using namespace std;

// Main Execution
bool hasHamiltonian(bool graph[][MAXN], int NVERT);
bool hasHamUtil(bool graph[][MAXN], int path[], int pos, int V);
bool isSafe(int v, bool graph[][MAXN], int path[], int pos);

int main(int argc, char *argv[]) {

    int NVERT;
    int timesLoop = 0;
    bool hasPath;

    while( cin >> NVERT ){
        // adjacency matrix of bools
        bool adjMat[MAXN][MAXN];

        // fill adjacency matrix with input
        int val;
        for( int i = 0; i < NVERT; i ++ ){
            for( int j = 0; j < NVERT; j++ ){
                cin >> val;
                adjMat[i][j] = val;
            }
        }

        // check if has hamiltonian path
        hasPath = hasHamiltonian(adjMat, NVERT);
        if( hasPath )
            cout << "Graph " << timesLoop << " contains a Hamiltonian path." << endl;
        else
            cout << "Graph " << timesLoop << " does not contain a Hamiltonian path." << endl;

        timesLoop++;
    }

    return EXIT_SUCCESS;
}

// check thats vertex v can be added in next position of hamiltonian path
// requires checking that it is adjacent and that it hasn't been included alread
bool isSafe(int v, bool graph[][MAXN], int path[], int pos)
{
    // check if adjacent to previus vertex
    if (graph [ path[pos-1] ][ v ] == 0)
        return false;
 
    // check if already included in path
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
 
    return true;
}

// recursive function to find hamiltonian path 
bool hasHamUtil(bool graph[][MAXN], int path[], int pos, int V)
{
    // stops when all vertices in the path
    if (pos == V)
        return true;
 
    // Find next candidate vertex for Hamiltonian path
    for (int v = 1; v < V; v++)
    {
        // Check if vertex can be added
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;
 
            // recursively find rest of path
            if (hasHamUtil (graph, path, pos+1, V) == true)
                return true;
 
            // if no solution down this path, remove v
            path[pos] = -1;
        }
    }
 
    // no vertex can be added to path constructed thus far
    return false;
}
 
// checks for hamiltonian path using backtracing
bool hasHamiltonian(bool graph[][MAXN], int NVERT){
    int *path = new int[NVERT];
    for (int i = 0; i < NVERT; i++)
        path[i] = -1;
 
    //vertex 0 is first vertex in path
    path[0] = 0;
    if ( hasHamUtil(graph, path, 1, NVERT) == false )
    {
        delete [] path;
        return false;
    }

    delete [] path;
    return true;
} 

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
