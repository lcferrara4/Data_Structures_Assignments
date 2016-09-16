Reading 03
==========

1. A is a maximum binary tree.

All of the trees are complete binary trees, which is a necessary component to be a heap.

However both B and C don't follow the rule that children nodes must be less than parent nodes. In B, 16 < 17. In C, 19 < 27.

2. Reheapification is the process necessary to maintain the priority ordering when a new entry is added to a binary heap. The complexity of this process is O(logN) when the tree has N entries. 

3. Selection sort
{9, 6, 0, 0, 7}
{7, 6, 0, 0, 9}
{0, 6, 0, 7, 9}
{0, 0, 6, 7, 9}
{0, 0, 6, 7, 9}

4. Insertion sort
{9, 6, 0, 0, 7}
{6, 9, 0, 0, 7}
{0, 6, 9, 0, 7}
{0, 0, 6, 9, 7}
{0, 0, 6, 7, 9} 
