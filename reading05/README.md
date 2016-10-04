Reading 05
==========

1. A binary heap has less than comparison between levels of the tree. Therefore, it is good for max/min searches. A binary search tree has less than relationship with left and right nodes on each level as well.

No, it cannot be both a binary heap and a binary search tree. To be a binary heap, both children would be either less than or greater than the parent. In a bst, the left child would have to be less but the right child would have to be greater than the parent. This couldn't happen in a binary heap.

2. You would print out all values in the binary tree in sorted order by conducting an in order traversal and printing when you reach each node. This would consist of a base case when the node is NULL, a recursive call to the left subtree, a print statement for the value of the node sent to the function, and then a recursive call to the right subtree. This would be O(n) because it would reach each node 1 time.

3.

1) Search: Average = O(log(n)), Worst = O(n)
2) Insert: Average = O(log(n)), Worst = O(n)
3) Remove: Average = O(log(n)), Worst = O(n)

The time complexities between average and worst are different, because in worst case a binary search tree ends up looking like a linked list and is no more efficient than that.

4. A B-Tree is different from a binary search tree in that a parent can have more than two children nodes and that each node can store multiple values. A B-Tree avoids the problem of an unbalanced tree that a binary search tree has by ensuring that every leaf has the same depth. Yet, it still has a sorted order, keeping its complexities for search, insert, and remove at O(log(n)) even in worst case. This makes it an attractive data structure for implementing large data storage systems because it can hold and sort large numbers of data entries without the possibility of becoming unbalanced and then O(n), which is way worse when n is large than O(log(n)). 
