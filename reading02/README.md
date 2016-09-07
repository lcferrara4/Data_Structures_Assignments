Reading 02
==========

Sorry this is late. I made a mistake in submitting to GitLab.

1. Binary Tree Height

The minimum height is zero with just a node (although it may be an empty tree in which case it has no height). Accessing the nodes in this tree, for example to print, would be O(1).

The maximum height is N-1 with each node at a different depth. To access all nodes would take O(N) time.

2. Array representation:

   0     1     2     3     4     5     6     7
[  R  |  O  |  G  |  U  |  E  |  O  |  N  |  E  ]

If the binary tree is complete, then it is better to use the array representation, because you know the positions and ordering of all the nodes in the array. Then you can use the formulas to get between parent node and left/ride children nodes. These make it easy for algorithms to traverse the tree and process particular data.

3. Traversals

Breadth-first: W, Y, R, D, B, I, O, F, U, L, A, R, A, E, D
I would use a queue for this traversal.

Depth-first: W, Y, D, F, U, B, L, A, R, I, R, A, O, E, D
I would use a stack for this traversal.

4. Shared Pointer:

#include <memory>
using namespace std;
struct Node {
	int value;
	unique_ptr<Node<int>> left;
	unique_ptr<Node<int>> right;
};

Benefits: Using smart pointers ensures RAII, preventing memory leaks. Also using the unique ptr makes sense in this situtation since each left or right node can only have one parent in a binary tree.
