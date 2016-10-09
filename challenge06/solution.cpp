// Challenge 06: Lowest Common Ancestor

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// struct for nodes of bst
struct Node{
    int value;
    Node * left;
    Node * right;

};

// struct for binary search tree
struct BST{
    Node * root;

    // destroys all nodes in tree to prevent memory leaks
    void deleteTree(Node *curr){
        if( curr != nullptr ){
            deleteTree(curr->left);
            deleteTree(curr->right);
            delete curr;
        }
    }

    // insert function to build the tree
    void insert(int val, Node *&curr){
        if( curr == nullptr ){
            curr = new Node;
            curr->value = val;
            curr->left = nullptr;
            curr->right = nullptr;

        } else if( val < curr->value ){
            if(curr->left != nullptr)
                insert(val, curr->left);
            else{
                curr->left = new Node;
                curr->left->value = val;
                curr->left->left = nullptr;
                curr->left->right = nullptr;   
            }  

        } else{
            if(curr->right != nullptr)
                insert(val, curr->right);
            else{
              curr->right = new Node;
              curr->right->value = val;
              curr->right->left = nullptr;
              curr->right->right = nullptr; 
            }
          }
        }
};

// function to find lowest common ancestor
int findLCA(BST*, int, int);

// breadth first search for debugging
void bfs(BST *bst);

// Main Execution
int main(int argc, char *argv[]) {
    int N, numPairs, i;
    int value;
   
    int value1, value2;
    int lca;

    BST *bst = new BST();

    cin >> N;
    while( N != -1 ){
        bst->root = nullptr;   

        // construct the tree
        for ( i = 0; i < N; i++ ){
            cin >> value;
            bst->insert(value, bst->root);
        }
    
        // traversal (for debugging)
        // bfs(bst);
        
        // get pairs
        cin >> numPairs;
        for ( i = 0; i < numPairs; i++){
            cin >> value1;
            cin >> value2;
            lca = findLCA(bst, value1, value2);              
            cout << lca << endl;
        }
        
        // update for next round
        cin >> N;
        if( N != -1){
            cout << "\n";
        }
        bst->deleteTree(bst->root);
    }

    delete bst;
    return EXIT_SUCCESS;
}

int findLCA(BST *bst, int val1, int val2){
    vector<int> parents;

    Node *curr = bst->root;

    // check if root is null
    while(curr != nullptr){ 

        // check if either value is equal to the current node
        if( val1 == curr->value || val2 == curr->value){
            return curr->value;
        }
        // if both values are less than the curr, move left
        else if( val1 < curr->value && val2 < curr->value ){
            if( curr->left == nullptr ){
                return curr->value;
            }
            curr = curr->left;
        }
        // if both values are greater than the curr, move right
        else if( val1 > curr->value && val2 > curr->value ){
            if( curr->right == nullptr ){
                return curr->value;
            } 
            curr = curr->right;
        }
        // if they differ, then this is the LCA
        else{
            return curr->value;
        }
    }            

    return 0;
}

void bfs(BST *bst){

    queue<Node*> q;    

    // if root isn't nullptr, push root onto queue
    if (bst->root){
        q.push(bst->root);  // push root onto queue
        cout << bst->root->value << " "; // print root value
    } else {
        cout << "NULL ";
    }
    // while the queue isn't empty, loop
    while (!q.empty()) {
        Node * temp = q.front(); // gets front of queue
        q.pop(); // pops front of queue

        if (temp->left) { // if left isn't nullptr
            q.push(temp->left); // push left onto queue
            cout << temp->left->value << " "; // print left value
        } else {
            cout << "NULL ";
        }

        if (temp->right) { // if right isn't nullptr
            q.push(temp->right); // push right onto queue
            cout << temp->right->value << " "; // print right value
        } else {
            cout << "NULL ";
        }
    } 

}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
