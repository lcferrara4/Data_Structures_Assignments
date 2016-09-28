// Challenge 05: BST
#include <iostream>
#include <vector>
#include <stddef.h>

using namespace std;

bool checkChildren( vector<int>, int, bool, int, int );

// Main Execution

int main(int argc, char *argv[]) {

    int N;
    int count = 0;
    bool bst;

    int value;
    vector<int> tree;

    // get input
    while ( cin >> N ){
        bst = 1;
        count++;
        
        for( int i = 0; i < N; i++ ){
            cin >> value;
            tree.push_back(value); 
        }
        
        // check tree
        bst = checkChildren(tree, 0, bst, 0, 0);

        // print result
        if ( bst ){
            cout << "Tree " << count << " is a BST" << endl;
        } else{
            cout << "Tree " << count << " is not a BST" << endl;
        }

        tree.clear();
    }
    return EXIT_SUCCESS;
}

bool checkChildren( vector<int> tree, int curr, bool bst, int min, int max ){


    // get indices of left and right children
    int left = 2 * curr + 1;
    int right = 2 * curr + 2;

    if ((min != 0 && tree[curr] <= min) || (max != 0 && tree[curr] > max)){
        return 0;
    }

    // check left child
    if( left >= tree.size() ){  // reached end of tree
        return 1;
    } else if( tree[left] <= tree[curr] && tree[left] != -1 ){
        bst = bst * checkChildren( tree, left, bst, min, tree[curr] );
    } else if( tree[left] != -1 ){  // violates bst rule
        return 0;
    }

    // check right child
    if( right >= tree.size() ){ // reached end of tree
        return 1;
    } else if( tree[right] > tree[curr] ){
        bst = bst * checkChildren( tree, right, bst, tree[curr], max );
    } else if( tree[right] != -1 ){ // violates bst rule
        return 0;
    }

    return bst;    
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
