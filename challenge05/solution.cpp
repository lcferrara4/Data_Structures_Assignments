// Challenge 05: BST
#include <iostream>
#include <vector>

using namespace std;

bool checkChildren( vector<int>, int, bool );

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
        bst = checkChildren(tree, 0, bst);

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

bool checkChildren( vector<int> tree, int curr, bool bst ){

    // get indices of left and right children
    int left = 2 * curr + 1;
    int right = 2 * curr + 2;

    // check left child
    if( left >= tree.size() ){  // reached end of tree
        return 1;
    } else if( tree[left] <= tree[curr] && tree[left] != -1 ){
        bst = bst * checkChildren( tree, left, bst );
    } else if( tree[left] != -1 ){  // violates bst rule
        return 0;
    }

    // check right child
    if( right >= tree.size() ){ // reached end of tree
        return 1;
    } else if( tree[right] > tree[curr] ){
        bst = bst * checkChildren( tree, right, bst );
    } else if( tree[right] != -1 ){ // violates bst rule
        return 0;
    }

    return bst;    
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
