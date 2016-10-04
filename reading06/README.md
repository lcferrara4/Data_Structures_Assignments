Reading 06
==========

1. In a left rotation, a right child node take the place of its parent and the parent becomes that node's left child. The left child of the original parent node is unaffected If the original right child had a left child, this node needs to be reconnected to be the right child of the original parent. The two nodes that swapped position also swap color. The lower node must be red to maintain the invariants of the red-black tree.

2. Invariants:

	1. The root node is black.
	2. No path has two red nodes in a row.
	3. Every path has the same number of black nodes.

3. Treaps are like BSTs, in that each node has a data value x that follows the rules of a BST. However, each node also has a unique numerical priority assigned at ranodm. A treap is also like a heap in that every node except the root follows the rule that the priority of the parent < priority of the child.

To insert a node into a treap, it gets assigned a value x and a random value for its priority p. The node is at first a leaf of the treap, in a way that follows the binary search tree property. However, at this point it may violate the heap property, in that parent.p > p. If this is the case. a rotation is performed so that the node becomes the parent of its parent node. We repeat this until the node either becomes the root or parent.p < p.

4. Time Complexities:

	1. Red-Black Trees

	* Search: Average = O(log(n)), Worst =O(log(n)) 

	* Insert: Average = O(log(n)), Worst = O(log(n))

	* Remove: Average = O(log(n)), Worst = O(log(n)) 

	2. Treaps

	* Search: Average = O(log(n)), Worst = O(n)

	* Insert: Average = O(log(n)), Worst = O(n)

	* Remove: Average = O(log(n)), Worst = O(n)

A treap has worst case time complexity of O(n) instead of O(log(n)) because it is balanced randomly, by a randomly assigned priority number. Therefore, it has a small chance of randomly being entirely unbalanced, leading to time complexities of O(n).

